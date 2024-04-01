/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:23:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:23:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// div the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_div_scalar(t_vec3 v1, float scalar)
{
	t_vec3	result;

	result.x = v1.x / scalar;
	result.y = v1.y / scalar;
	result.z = v1.z / scalar;
	return (result);
}

/// mult the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_mult(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

/// mult the x, y and z of v1 with a scalar and returns the result
t_vec3	vec3_mult_scalar(t_vec3 v1, float scalar)
{
	t_vec3	result;

	result.x = v1.x * scalar;
	result.y = v1.y * scalar;
	result.z = v1.z * scalar;
	return (result);
}

/// mult the x, y and z of v1 and v2 then add x, y,
/// z of v3 and returns the result
t_vec3	vec3_mult_add(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_vec3	result;

	result.x = v1.x * v2.x + v3.x;
	result.y = v1.y * v2.y + v3.y;
	result.z = v1.z * v2.z + v3.z;
	return (result);
}

/// returns the result of x * x + y * y + z * z
float	vec3_len_square(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
