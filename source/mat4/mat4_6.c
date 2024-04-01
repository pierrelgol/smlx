/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:25:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:25:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

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
