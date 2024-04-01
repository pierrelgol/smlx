/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:25:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:25:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

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
float	mat4_determinant(t_mat4x4 m, float *o, float *t)
{
	t = (float [16]){0};
	o = (float [16]){0};
	t[0] = m.data[10] * m.data[15];
	t[1] = m.data[14] * m.data[11];
	t[2] = m.data[6] * m.data[15];
	t[3] = m.data[14] * m.data[7];
	t[4] = m.data[6] * m.data[11];
	t[5] = m.data[10] * m.data[7];
	t[6] = m.data[2] * m.data[15];
	t[7] = m.data[14] * m.data[3];
	t[8] = m.data[2] * m.data[11];
	t[9] = m.data[10] * m.data[3];
	t[10] = m.data[2] * m.data[7];
	t[11] = m.data[6] * m.data[3];
	o[0] = (t[0] * m.data[5] + t[3] * m.data[9] + t[4] * m.data[13]) - (t[1]
			* m.data[5] + t[2] * m.data[9] + t[5] * m.data[13]);
	o[1] = (t[1] * m.data[1] + t[6] * m.data[9] + t[9] * m.data[13]) - (t[0]
			* m.data[1] + t[7] * m.data[9] + t[8] * m.data[13]);
	o[2] = (t[2] * m.data[1] + t[7] * m.data[5] + t[10] * m.data[13]) - (t[3]
			* m.data[1] + t[6] * m.data[5] + t[11] * m.data[13]);
	o[3] = (t[5] * m.data[1] + t[8] * m.data[5] + t[11] * m.data[9]) - (t[4]
			* m.data[1] + t[9] * m.data[5] + t[10] * m.data[9]);
	return (1.0f / (m.data[0] * o[0] + m.data[4] * o[1] + m.data[8] * o[2]
			+ m.data[12] * o[3]));
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
