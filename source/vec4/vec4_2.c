/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:27:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:27:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// add and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_add(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	result.w = v1.w + v2.w;
	return (result);
}

/// sub and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_sub(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	result.w = v1.w - v2.w;
	return (result);
}

/// div and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_div(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	result.w = v1.w / v2.w;
	return (result);
}

/// div the x, y, z, and w of v1 by scalar and returns the result
t_vec4	vec4_div_scalar(t_vec4 v1, float scalar)
{
	t_vec4	result;

	result.x = v1.x / scalar;
	result.y = v1.y / scalar;
	result.z = v1.z / scalar;
	result.w = v1.w / scalar;
	return (result);
}

/// mult and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_mult(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	result.w = v1.w * v2.w;
	return (result);
}
