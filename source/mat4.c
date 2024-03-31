/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:57:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/31 15:57:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

/// returns a "default" matrix
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
t_mat4x4 *mat4_create(t_allocator *allocator)
{
	t_mat4x4 *m;

	m = allocator->create(allocator, sizeof(t_mat4x4));
	memory_set(m->elements, 0x00, sizeof(float) * 16);
	return (m);
}

/// returns a "default" matrix
/// {1, 0, 0, 0}
/// {0, 1, 0, 0}
/// {0, 0, 1, 0}
/// {0, 0, 0, 1}
t_mat4x4 *mat4_identity(t_allocator *allocator)
{
	t_mat4x4 *m;

	m = allocator->create(allocator, sizeof(t_mat4x4));
	memory_set(m->elements, 0x00, sizeof(float) * 16);
	m->elements[0] = 1.0f;
	m->elements[5] = 1.0f;
	m->elements[10] = 1.0f;
	m->elements[15] = 1.0f;
	return (m);
}

/// returns the result of multiplying matrix m1 and m2
t_mat4x4 *mat4_mult(t_allocator *allocator, t_mat4x4 *m1, t_mat4x4 *m2)
{
	t_mat4x4 *out;
	float    *dst_ptr;
	float    *m1_ptr;
	;
	uint32_t i;
	uint32_t j;

	out = mat4_identity(allocator);
	dst_ptr = out->elements;
	m1_ptr = m1->elements;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*dst_ptr = m1_ptr[0] * m2->elements[0 + j];
			*dst_ptr = m1_ptr[1] * m2->elements[4 + j];
			*dst_ptr = m1_ptr[2] * m2->elements[8 + j];
			*dst_ptr = m1_ptr[3] * m2->elements[12 + j];
			++j;
		}
		m1_ptr += 4;
		++i;
	}
	return (out);
}

/// returns an ortographic projection matrix
/// lrb is for (left, right, bottom)
/// tnf is for (top, near_clip, far_clip)
t_mat4x4 *mat4_orthographic(t_allocator *allocator, t_vec3 lrb, t_vec3 tnf)
{
	t_mat4x4 *out;
	float     lr;
	float     bt;
	float     nf;

	lr = 1.0f / (lrb.x - lrb.y);
	bt = 1.0f / (lrb.z - tnf.x);
	nf = 1.0f / (tnf.y - tnf.z);
	out = mat4_identity(allocator);
	out->elements[0] = -2.0f * lr;
	out->elements[5] = -2.0f * bt;
	out->elements[10] = -2.0f * nf;
	out->elements[12] = (lrb.x + lrb.y) * lr;
	out->elements[13] = (tnf.x + lrb.z) * bt;
	out->elements[14] = (tnf.z + tnf.y) * nf;
	return (out);
}

/// returns an perspective projection matrix
// t_vec2 fov_ar (fov_rad, aspect_ratio)
// t_vec2 nc_fc (near_clip, far_clip)
t_mat4x4 *mat4_perspective(t_allocator *allocator, t_vec2 fov_ar, t_vec2 nc_fc)
{
	t_mat4x4 *out;
	float     half_tan_fov;

	half_tan_fov = tanf(fov_ar.x * 0.5f);
	out = mat4_identity(allocator);
	out->elements[0] = 1.0f / (fov_ar.y * half_tan_fov);
	out->elements[5] = 1.0f / half_tan_fov;
	out->elements[10] = -((nc_fc.y + nc_fc.x) / (nc_fc.y - nc_fc.x));
	out->elements[11] = -1.0f;
	out->elements[14] = -((2.0f * nc_fc.y * nc_fc.x) / (nc_fc.y - nc_fc.x));
	return (out);
}
/// creates and return a loot-at matrix for looking at target from the
/// perspective of the postion
/// @TODO verify correctness (kohi23 16:00)
t_mat4x4 *mat4_look_at(t_allocator *allocator, t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_mat4x4 *out;
	t_vec3    x_axis;
	t_vec3    y_axis;
	t_vec3    z_axis;

	z_axis = vec3_normalized(vec3_sub(target, pos));
	x_axis = vec3_normalized(vec3_cross(z_axis, up));
	y_axis = vec3_cross(x_axis, z_axis);
	out->elements[0] = x_axis.x;
	out->elements[1] = y_axis.x;
	out->elements[2] = -z_axis.x;
	out->elements[4] = x_axis.y;
	out->elements[5] = y_axis.y;
	out->elements[6] = -z_axis.y;
	out->elements[8] = x_axis.z;
	out->elements[9] = y_axis.z;
	out->elements[10] = -z_axis.z;
	out->elements[12] = -vec3_dot(x_axis, pos);
	out->elements[13] = -vec3_dot(y_axis, pos);
	out->elements[14] = vec3_dot(z_axis, pos);
	out->elements[15] = 1.0f;
	return (out);
}

/// returns a transposed copy of the provided matrix (row->columns)
t_mat4x4 *mat4_transpose(t_allocator *allocator, t_mat4x4 *mat)
{
	t_mat4x4	*out;

	out = mat4_identity(allocator);
	out->elements[0] = mat->elements[0];
	out->elements[1] = mat->elements[4];
	out->elements[2] = mat->elements[8];
	out->elements[3] = mat->elements[12];
	out->elements[4] = mat->elements[1];
	out->elements[5] = mat->elements[5];
	out->elements[6] = mat->elements[9];
	out->elements[7] = mat->elements[13];
	out->elements[8] = mat->elements[2];
	out->elements[9] = mat->elements[6];
	out->elements[10] = mat->elements[10];
	out->elements[11] = mat->elements[14];
	out->elements[12] = mat->elements[3];
	out->elements[13] = mat->elements[7];
	out->elements[14] = mat->elements[11];
	out->elements[15] = mat->elements[15];
	return (out);
}

static void mat4_inverse2(float t[24], float m[16]);
static void mat4_inverse3(float o[16], float t[24], float m[16]);
static void mat4_inverse4(float o[16], float t[24], float m[16], float d);

/// creates and returns the inverse value of a matrix
t_mat4x4 *mat4_inverse1(t_allocator *allocator, t_mat4x4 *matrix)
{
	t_mat4x4 *out_matrix;
	float    *t;
	float    *o;
	float    *m;
	float     d;

	t = (float[24]){0};
	m = matrix->elements;
	out_matrix = mat4_create(allocator);
	o = out_matrix->elements;
	mat4_inverse2(t, m);
	d = 1.0f / (m[0] * o[0] + m[4] * o[1] + m[8] * o[2] + m[12] * o[3]);
	mat4_inverse3(o, t, m);
	mat4_inverse4(o, t, m, d);

	return (out_matrix);
}

static void mat4_inverse2(float t[24], float m[16])
{
	t[0] = m[10] * m[15];
	t[1] = m[14] * m[11];
	t[2] = m[6] * m[15];
	t[3] = m[14] * m[7];
	t[4] = m[6] * m[11];
	t[5] = m[10] * m[7];
	t[6] = m[2] * m[15];
	t[7] = m[14] * m[3];
	t[8] = m[2] * m[11];
	t[9] = m[10] * m[3];
	t[10] = m[2] * m[7];
	t[11] = m[6] * m[3];
	t[12] = m[8] * m[13];
	t[13] = m[12] * m[9];
	t[14] = m[4] * m[13];
	t[15] = m[12] * m[5];
	t[16] = m[4] * m[9];
	t[17] = m[8] * m[5];
	t[18] = m[0] * m[13];
	t[19] = m[12] * m[1];
	t[20] = m[0] * m[9];
	t[21] = m[8] * m[1];
	t[22] = m[0] * m[5];
	t[23] = m[4] * m[1];
}

static void mat4_inverse3(float o[16], float t[24], float m[16])
{
	o[0] = (t[0] * m[5] + t[3] * m[9] + t[4] * m[13]) - (t[1] * m[5] + t[2] * m[9] + t[5] * m[13]);
	o[1] = (t[1] * m[1] + t[6] * m[9] + t[9] * m[13]) - (t[0] * m[1] + t[7] * m[9] + t[8] * m[13]);
	o[2] = (t[2] * m[1] + t[7] * m[5] + t[10] * m[13]) - (t[3] * m[1] + t[6] * m[5] + t[11] * m[13]);
	o[3] = (t[5] * m[1] + t[8] * m[5] + t[11] * m[9]) - (t[4] * m[1] + t[9] * m[5] + t[10] * m[9]);
}

static void mat4_inverse4(float o[16], float t[24], float m[16], float d)
{
	o[0] = d * o[0];
	o[1] = d * o[1];
	o[2] = d * o[2];
	o[3] = d * o[3];
	o[4] = d * ((t[1] * m[4] + t[2] * m[8] + t[5] * m[12]) - (t[0] * m[4] + t[3] * m[8] + t[4] * m[12]));
	o[5] = d * ((t[0] * m[0] + t[7] * m[8] + t[8] * m[12]) - (t[1] * m[0] + t[6] * m[8] + t[9] * m[12]));
	o[6] = d * ((t[3] * m[0] + t[6] * m[4] + t[11] * m[12]) - (t[2] * m[0] + t[7] * m[4] + t[10] * m[12]));
	o[7] = d * ((t[4] * m[0] + t[9] * m[4] + t[10] * m[8]) - (t[5] * m[0] + t[8] * m[4] + t[11] * m[8]));
	o[8] = d * ((t[12] * m[7] + t[15] * m[11] + t[16] * m[15]) - (t[13] * m[7] + t[14] * m[11] + t[17] * m[15]));
	o[9] = d * ((t[13] * m[3] + t[18] * m[11] + t[21] * m[15]) - (t[12] * m[3] + t[19] * m[11] + t[20] * m[15]));
	o[10] = d * ((t[14] * m[3] + t[19] * m[7] + t[22] * m[15]) - (t[15] * m[3] + t[18] * m[7] + t[23] * m[15]));
	o[11] = d * ((t[17] * m[3] + t[20] * m[7] + t[23] * m[11]) - (t[16] * m[3] + t[21] * m[7] + t[22] * m[11]));
	o[12] = d * ((t[14] * m[10] + t[17] * m[14] + t[13] * m[6]) - (t[16] * m[14] + t[12] * m[6] + t[15] * m[10]));
	o[13] = d * ((t[20] * m[14] + t[12] * m[2] + t[19] * m[10]) - (t[18] * m[10] + t[21] * m[14] + t[13] * m[2]));
	o[14] = d * ((t[18] * m[6] + t[23] * m[14] + t[15] * m[2]) - (t[22] * m[14] + t[14] * m[2] + t[19] * m[6]));
	o[15] = d * ((t[22] * m[10] + t[16] * m[2] + t[21] * m[6]) - (t[20] * m[6] + t[23] * m[10] + t[17] * m[2]));
}

/// returns a translation matrix from a t_vec3 postion
t_mat4x4 *mat4_translation(t_allocator *allocator, t_vec3 position)
{
	t_mat4x4 *out;

	out = mat4_identity(allocator);
	out->elements[12] = position.x;
	out->elements[13] = position.y;
	out->elements[14] = position.z;
	return (out);
}

/// returns a scaling matrix from a t_vec3 scale
t_mat4x4 *mat4_scale(t_allocator *allocator, t_vec3 scale)
{
	t_mat4x4 *out;

	out = mat4_identity(allocator);
	out->elements[0] = scale.x;
	out->elements[5] = scale.y;
	out->elements[10] = scale.z;

	return (out);
}

/// returns a matrix to modify the angle of x
t_mat4x4 *mat4_euler_x(t_allocator *allocator, float angle_radian)
{
	t_mat4x4 *out;
	float     cos;
	float     sin;

	cos = cosf(angle_radian);
	sin = sinf(angle_radian);
	out = mat4_identity(allocator);
	out->elements[5] = cos;
	out->elements[6] = sin;
	out->elements[9] = -sin;
	out->elements[10] = cos;

	return (out);
}

/// returns a matrix to modify the angle of y
t_mat4x4 *mat4_euler_y(t_allocator *allocator, float angle_radian)
{
	t_mat4x4 *out;
	float     cos;
	float     sin;

	cos = cosf(angle_radian);
	sin = sinf(angle_radian);
	out = mat4_identity(allocator);
	out->elements[0] = cos;
	out->elements[2] = -sin;
	out->elements[8] = sin;
	out->elements[10] = cos;

	return (out);
}

/// returns a matrix to modify the angle of z
t_mat4x4 *mat4_euler_z(t_allocator *allocator, float angle_radian)
{
	t_mat4x4 *out;
	float     cos;
	float     sin;

	cos = cosf(angle_radian);
	sin = sinf(angle_radian);
	out = mat4_identity(allocator);
	out->elements[0] = cos;
	out->elements[1] = sin;
	out->elements[4] = -sin;
	out->elements[5] = cos;

	return (out);
}

/// returns a matrix to modify the angle of xyz
t_mat4x4 *mat4_euler_xyz(t_allocator *allocator, float x_ar, float y_ar, float z_ar)
{
	t_mat4x4	*out;
	t_mat4x4	*temp;
	t_mat4x4	*rx;
	t_mat4x4	*ry;
	t_mat4x4	*rz;

	rx = mat4_euler_x(allocator, x_ar);
	ry = mat4_euler_y(allocator, y_ar);
	rz = mat4_euler_z(allocator, z_ar);
	temp = mat4_mult(allocator, rx, ry);
	out = mat4_mult(allocator, temp, rz);
	allocator->destroy(allocator, temp);
	allocator->destroy(allocator, rx);
	allocator->destroy(allocator, ry);
	allocator->destroy(allocator, rz);
	return (out);
}

/// returns a forward vector relative to the provided matrix
t_vec3	mat4_forward(t_mat4x4 *matrix)
{
	t_vec3 forward;

	forward.x = -matrix->elements[2];
	forward.y = -matrix->elements[6];
	forward.z = -matrix->elements[10];
	vec3_normalize(&forward);
	return (forward);
}



/// returns a backward vector relative to the provided matrix
t_vec3	mat4_backward(t_mat4x4 *matrix)
{
	t_vec3 backward;

	backward.x = matrix->elements[2];
	backward.y = matrix->elements[6];
	backward.z = matrix->elements[10];
	vec3_normalize(&backward);
	return (backward);
}

/// returns a upward vector relative to the provided matrix
t_vec3	mat4_up(t_mat4x4 *matrix)
{
	t_vec3 upward;

	upward.x = matrix->elements[1];
	upward.y = matrix->elements[5];
	upward.z = matrix->elements[9];
	vec3_normalize(&upward);
	return (upward);
}

/// returns a downward vector relative to the provided matrix
t_vec3	mat4_down(t_mat4x4 *matrix)
{
	t_vec3 downward;

	downward.x = -matrix->elements[1];
	downward.y = -matrix->elements[5];
	downward.z = -matrix->elements[9];
	vec3_normalize(&downward);
	return (downward);
}

/// returns a left vector relative to the provided matrix
t_vec3	mat4_left(t_mat4x4 *matrix)
{
	t_vec3 right;

	right.x = -matrix->elements[0];
	right.y = -matrix->elements[4];
	right.z = -matrix->elements[8];
	vec3_normalize(&right);
	return (right);
}

/// returns a right vector relative to the provided matrix
t_vec3	mat4_right(t_mat4x4 *matrix)
{
	t_vec3 left;

	left.x = -matrix->elements[0];
	left.y = -matrix->elements[4];
	left.z = -matrix->elements[8];
	vec3_normalize(&left);
	return (left);
}

