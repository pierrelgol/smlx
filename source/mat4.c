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
t_mat4x4	mat4_create(void)
{
	t_mat4x4	m;

	smlx_bzero(m.data,sizeof(float) * 16);
	return (m);
}

/// returns a "default" matrix
/// {1, 0, 0, 0}
/// {0, 1, 0, 0}
/// {0, 0, 1, 0}
/// {0, 0, 0, 1}
t_mat4x4	mat4_identity(void)
{
	t_mat4x4	m;

	smlx_bzero(m.data,sizeof(float) * 16);
	m.data[0] = 1.0f;
	m.data[5] = 1.0f;
	m.data[10] = 1.0f;
	m.data[15] = 1.0f;
	return (m);
}

/// returns the result of multiplying matrix m1 and m2
t_mat4x4	mat4_mult(t_mat4x4 m1, t_mat4x4 m2)
{
	t_mat4x4	out;
	float		*dst_ptr;
	float		*m1_ptr;
	uint32_t	i;
	uint32_t	j;

	out = mat4_identity();
	dst_ptr = out.data;
	m1_ptr = m1.data;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*dst_ptr = m1_ptr[0] * m2.data[0 + j] + m1_ptr[1] * m2.data[4 + j]
				+ m1_ptr[2] * m2.data[8 + j] + m1_ptr[3] * m2.data[12 + j];
			++dst_ptr;
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
t_mat4x4	mat4_orthographic(t_vec3 lrb, t_vec3 tnf)
{
	t_mat4x4	out;
	float		lr;
	float		bt;
	float		nf;

	lr = 1.0f / (lrb.x - lrb.y);
	bt = 1.0f / (lrb.z - tnf.x);
	nf = 1.0f / (tnf.y - tnf.z);
	out = mat4_identity();
	out.data[0] = -2.0f * lr;
	out.data[5] = -2.0f * bt;
	out.data[10] = -2.0f * nf;
	out.data[12] = (lrb.x + lrb.y) * lr;
	out.data[13] = (tnf.x + lrb.z) * bt;
	out.data[14] = (tnf.z + tnf.y) * nf;
	return (out);
}

/// returns an perspective projection matrix
// t_vec2 fov_ar (fov_rad, aspect_ratio)
// t_vec2 nc_fc (near_clip, far_clip)
t_mat4x4	mat4_perspective(t_vec2 fov_ar, t_vec2 nc_fc)
{
	t_mat4x4	out;
	float		half_tan_fov;

	half_tan_fov = tanf(fov_ar.x * 0.5f);
	out = mat4_create();
	out.data[0] = 1.0f / (fov_ar.y * half_tan_fov);
	out.data[5] = 1.0f / half_tan_fov;
	out.data[10] = -((nc_fc.y + nc_fc.x) / (nc_fc.y - nc_fc.x));
	out.data[11] = -1.0f;
	out.data[14] = -((2.0f * nc_fc.y * nc_fc.x) / (nc_fc.y - nc_fc.x));
	return (out);
}
/// creates and return a loot-at matrix for looking at target from the
/// perspective of the postion
/// @TODO verify correctness (kohi23 16:00)
t_mat4x4	mat4_look_at(t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_mat4x4	out;
	t_vec3		x_axis;
	t_vec3		y_axis;
	t_vec3		z_axis;

	out = mat4_create();
	z_axis = vec3_normalized(vec3_sub(target, pos));
	x_axis = vec3_normalized(vec3_cross(z_axis, up));
	y_axis = vec3_cross(x_axis, z_axis);
	out.data[0] = x_axis.x;
	out.data[1] = y_axis.x;
	out.data[2] = -z_axis.x;
	out.data[4] = x_axis.y;
	out.data[5] = y_axis.y;
	out.data[6] = -z_axis.y;
	out.data[8] = x_axis.z;
	out.data[9] = y_axis.z;
	out.data[10] = -z_axis.z;
	out.data[12] = -vec3_dot(x_axis, pos);
	out.data[13] = -vec3_dot(y_axis, pos);
	out.data[14] = vec3_dot(z_axis, pos);
	out.data[15] = 1.0f;
	return (out);
}

t_mat4x4	mat4_inverse(t_mat4x4 matrix)
{
	const float	*m = matrix.data;
	float		t0;
	float		t1;
	float		t2;
	float		t3;
	float		t4;
	float		t5;
	float		t6;
	float		t7;
	float		t8;
	float		t9;
	float		t10;
	float		t11;
	float		t12;
	float		t13;
	float		t14;
	float		t15;
	float		t16;
	float		t17;
	float		t18;
	float		t19;
	float		t20;
	float		t21;
	float		t22;
	float		t23;
	t_mat4x4	out_matrix;
	float		*o;
	float		d;

	t0 = m[10] * m[15];
	t1 = m[14] * m[11];
	t2 = m[6] * m[15];
	t3 = m[14] * m[7];
	t4 = m[6] * m[11];
	t5 = m[10] * m[7];
	t6 = m[2] * m[15];
	t7 = m[14] * m[3];
	t8 = m[2] * m[11];
	t9 = m[10] * m[3];
	t10 = m[2] * m[7];
	t11 = m[6] * m[3];
	t12 = m[8] * m[13];
	t13 = m[12] * m[9];
	t14 = m[4] * m[13];
	t15 = m[12] * m[5];
	t16 = m[4] * m[9];
	t17 = m[8] * m[5];
	t18 = m[0] * m[13];
	t19 = m[12] * m[1];
	t20 = m[0] * m[9];
	t21 = m[8] * m[1];
	t22 = m[0] * m[5];
	t23 = m[4] * m[1];
	o = out_matrix.data;
	o[0] = (t0 * m[5] + t3 * m[9] + t4 * m[13]) - (t1 * m[5] + t2 * m[9] + t5
			* m[13]);
	o[1] = (t1 * m[1] + t6 * m[9] + t9 * m[13]) - (t0 * m[1] + t7 * m[9] + t8
			* m[13]);
	o[2] = (t2 * m[1] + t7 * m[5] + t10 * m[13]) - (t3 * m[1] + t6 * m[5] + t11
			* m[13]);
	o[3] = (t5 * m[1] + t8 * m[5] + t11 * m[9]) - (t4 * m[1] + t9 * m[5] + t10
			* m[9]);
	d = 1.0f / (m[0] * o[0] + m[4] * o[1] + m[8] * o[2] + m[12] * o[3]);
	o[0] = d * o[0];
	o[1] = d * o[1];
	o[2] = d * o[2];
	o[3] = d * o[3];
	o[4] = d * ((t1 * m[4] + t2 * m[8] + t5 * m[12]) - (t0 * m[4] + t3 * m[8]
				+ t4 * m[12]));
	o[5] = d * ((t0 * m[0] + t7 * m[8] + t8 * m[12]) - (t1 * m[0] + t6 * m[8]
				+ t9 * m[12]));
	o[6] = d * ((t3 * m[0] + t6 * m[4] + t11 * m[12]) - (t2 * m[0] + t7 * m[4]
				+ t10 * m[12]));
	o[7] = d * ((t4 * m[0] + t9 * m[4] + t10 * m[8]) - (t5 * m[0] + t8 * m[4]
				+ t11 * m[8]));
	o[8] = d * ((t12 * m[7] + t15 * m[11] + t16 * m[15]) - (t13 * m[7] + t14
				* m[11] + t17 * m[15]));
	o[9] = d * ((t13 * m[3] + t18 * m[11] + t21 * m[15]) - (t12 * m[3] + t19
				* m[11] + t20 * m[15]));
	o[10] = d * ((t14 * m[3] + t19 * m[7] + t22 * m[15]) - (t15 * m[3] + t18
				* m[7] + t23 * m[15]));
	o[11] = d * ((t17 * m[3] + t20 * m[7] + t23 * m[11]) - (t16 * m[3] + t21
				* m[7] + t22 * m[11]));
	o[12] = d * ((t14 * m[10] + t17 * m[14] + t13 * m[6]) - (t16 * m[14] + t12
				* m[6] + t15 * m[10]));
	o[13] = d * ((t20 * m[14] + t12 * m[2] + t19 * m[10]) - (t18 * m[10] + t21
				* m[14] + t13 * m[2]));
	o[14] = d * ((t18 * m[6] + t23 * m[14] + t15 * m[2]) - (t22 * m[14] + t14
				* m[2] + t19 * m[6]));
	o[15] = d * ((t22 * m[10] + t16 * m[2] + t21 * m[6]) - (t20 * m[6] + t23
				* m[10] + t17 * m[2]));
	return (out_matrix);
}

/// returns a transposed copy of the provided matrix (row->columns)
t_mat4x4	mat4_transposed(t_mat4x4 mat)
{
	t_mat4x4	out;

	out = mat4_identity();
	out.data[0] = mat.data[0];
	out.data[1] = mat.data[4];
	out.data[2] = mat.data[8];
	out.data[3] = mat.data[12];
	out.data[4] = mat.data[1];
	out.data[5] = mat.data[5];
	out.data[6] = mat.data[9];
	out.data[7] = mat.data[13];
	out.data[8] = mat.data[2];
	out.data[9] = mat.data[6];
	out.data[10] = mat.data[10];
	out.data[11] = mat.data[14];
	out.data[12] = mat.data[3];
	out.data[13] = mat.data[7];
	out.data[14] = mat.data[11];
	out.data[15] = mat.data[15];
	return (out);
}

/// returns the determinant of the provided matrix
float	mat4_determinant(t_mat4x4 matrix)
{
	float	*m;
	float	*o;
	float	*t;

	t = (float[16]){0};
	o = (float[16]){0};
	m = matrix.data;
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
	o[0] = (t[0] * m[5] + t[3] * m[9] + t[4] * m[13]) - (t[1] * m[5] + t[2]
			* m[9] + t[5] * m[13]);
	o[1] = (t[1] * m[1] + t[6] * m[9] + t[9] * m[13]) - (t[0] * m[1] + t[7]
			* m[9] + t[8] * m[13]);
	o[2] = (t[2] * m[1] + t[7] * m[5] + t[10] * m[13]) - (t[3] * m[1] + t[6]
			* m[5] + t[11] * m[13]);
	o[3] = (t[5] * m[1] + t[8] * m[5] + t[11] * m[9]) - (t[4] * m[1] + t[9]
			* m[5] + t[10] * m[9]);
	return (1.0f / (m[0] * o[0] + m[4] * o[1] + m[8] * o[2] + m[12] * o[3]));
}

/// returns a translation matrix from a t_vec3 postion
t_mat4x4	mat4_translation(t_vec3 position)
{
	t_mat4x4	out;

	out = mat4_identity();
	out.data[12] = position.x;
	out.data[13] = position.y;
	out.data[14] = position.z;
	return (out);
}

/// returns a scaling matrix from a t_vec3 scale
t_mat4x4	mat4_scale(t_vec3 scale)
{
	t_mat4x4	out;

	out = mat4_identity();
	out.data[0] = scale.x;
	out.data[5] = scale.y;
	out.data[10] = scale.z;
	return (out);
}

/// returns a matrix to modify the angle of x
t_mat4x4	mat4_euler_x(float angle_radian)
{
	t_mat4x4	out;
	float		cos;
	float		sin;

	cos = cosf(angle_radian);
	sin = sinf(angle_radian);
	out = mat4_identity();
	out.data[5] = cos;
	out.data[6] = sin;
	out.data[9] = -sin;
	out.data[10] = cos;
	return (out);
}

/// returns a matrix to modify the angle of y
t_mat4x4	mat4_euler_y(float angle_radian)
{
	t_mat4x4	out;
	float		cos;
	float		sin;

	cos = cosf(angle_radian);
	sin = sinf(angle_radian);
	out = mat4_identity();
	out.data[0] = cos;
	out.data[2] = -sin;
	out.data[8] = sin;
	out.data[10] = cos;
	return (out);
}

/// returns a matrix to modify the angle of z
t_mat4x4	mat4_euler_z(float angle_radian)
{
	t_mat4x4	out;
	float		cos;
	float		sin;

	cos = cosf(angle_radian);
	sin = sinf(angle_radian);
	out = mat4_identity();
	out.data[0] = cos;
	out.data[1] = sin;
	out.data[4] = -sin;
	out.data[5] = cos;
	return (out);
}

/// returns a matrix to modify the angle of xyz
t_mat4x4	mat4_euler_xyz(float x_ar, float y_ar, float z_ar)
{
	t_mat4x4	out;
	t_mat4x4	temp;
	t_mat4x4	rx;
	t_mat4x4	ry;
	t_mat4x4	rz;

	rx = mat4_euler_x(x_ar);
	ry = mat4_euler_y(y_ar);
	rz = mat4_euler_z(z_ar);
	temp = mat4_mult(rx, ry);
	out = mat4_mult(temp, rz);
	return (out);
}

/// returns a forward vector relative to the provided matrix
t_vec3	mat4_forward(t_mat4x4 matrix)
{
	t_vec3	forward;

	forward.x = -matrix.data[2];
	forward.y = -matrix.data[6];
	forward.z = -matrix.data[10];
	vec3_normalize(&forward);
	return (forward);
}

/// returns a backward vector relative to the provided matrix
t_vec3	mat4_backward(t_mat4x4 matrix)
{
	t_vec3	backward;

	backward.x = matrix.data[2];
	backward.y = matrix.data[6];
	backward.z = matrix.data[10];
	vec3_normalize(&backward);
	return (backward);
}

/// returns a upward vector relative to the provided matrix
t_vec3	mat4_up(t_mat4x4 matrix)
{
	t_vec3	upward;

	upward.x = matrix.data[1];
	upward.y = matrix.data[5];
	upward.z = matrix.data[9];
	vec3_normalize(&upward);
	return (upward);
}

/// returns a downward vector relative to the provided matrix
t_vec3	mat4_down(t_mat4x4 matrix)
{
	t_vec3	downward;

	downward.x = -matrix.data[1];
	downward.y = -matrix.data[5];
	downward.z = -matrix.data[9];
	vec3_normalize(&downward);
	return (downward);
}

/// returns a left vector relative to the provided matrix
t_vec3	mat4_left(t_mat4x4 matrix)
{
	t_vec3	right;

	right.x = -matrix.data[0];
	right.y = -matrix.data[4];
	right.z = -matrix.data[8];
	vec3_normalize(&right);
	return (right);
}

/// returns a right vector relative to the provided matrix
t_vec3	mat4_right(t_mat4x4 matrix)
{
	t_vec3	left;

	left.x = -matrix.data[0];
	left.y = -matrix.data[4];
	left.z = -matrix.data[8];
	vec3_normalize(&left);
	return (left);
}

/// returns the position relative to the provided matrix
t_vec3	mat4_position(t_mat4x4 matrix)
{
	t_vec3	pos;

	pos.x = matrix.data[12];
	pos.y = matrix.data[13];
	pos.z = matrix.data[14];
	vec3_normalize(&pos);
	return (pos);
}

/// returns the result of the multiplication m * v
t_vec3	mat4_mult_vec3(t_mat4x4 m, t_vec3 v)
{
	t_vec3	result;

	result.x = v.x * m.data[0] + v.y * m.data[1] + v.z * m.data[2] + m.data[3];
	result.y = v.x * m.data[4] + v.y * m.data[5] + v.z * m.data[6] + m.data[7];
	result.z = v.x * m.data[8] + v.y * m.data[9] + v.z * m.data[10]
		+ m.data[11];
	return (result);
}

/// returns the result of the multiplication v * m
t_vec3	vec3_mult_mat4(t_vec3 v, t_mat4x4 m)
{
	t_vec3	result;

	result.x = v.x * m.data[0] + v.y * m.data[4] + v.z * m.data[8] + m.data[12];
	result.y = v.x * m.data[1] + v.y * m.data[5] + v.z * m.data[9] + m.data[13];
	result.z = v.x * m.data[2] + v.y * m.data[6] + v.z * m.data[10]
		+ m.data[14];
	return (result);
}

t_vec4	mat4_mult_vec4(t_mat4x4 m, t_vec4 v)
{
	t_vec4	result;

	result.x = v.x * m.data[0] + v.y * m.data[1] + v.z * m.data[2] + v.w
		* m.data[3];
	result.y = v.x * m.data[4] + v.y * m.data[5] + v.z * m.data[6] + v.w
		* m.data[7];
	result.z = v.x * m.data[8] + v.y * m.data[9] + v.z * m.data[10] + v.w
		* m.data[11];
	result.w = v.x * m.data[12] + v.y * m.data[13] + v.z * m.data[14] + v.w
		* m.data[15];
	return (result);
}

t_vec4	vec4_mult_mat4(t_vec4 v, t_mat4x4 m)
{
	t_vec4	result;

	result.x = v.x * m.data[0] + v.y * m.data[4] + v.z * m.data[8] + v.w
		* m.data[12];
	result.y = v.x * m.data[1] + v.y * m.data[5] + v.z * m.data[9] + v.w
		* m.data[13];
	result.z = v.x * m.data[2] + v.y * m.data[6] + v.z * m.data[10] + v.w
		* m.data[14];
	result.w = v.x * m.data[3] + v.y * m.data[7] + v.z * m.data[11] + v.w
		* m.data[15];
	return (result);
}
