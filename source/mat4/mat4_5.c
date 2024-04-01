/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:25:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:25:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

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
