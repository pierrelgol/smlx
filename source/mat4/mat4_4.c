/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:25:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:25:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

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
