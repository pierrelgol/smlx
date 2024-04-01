/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:23:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:23:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// creates a t_vec3 with value x, y and z set to {0,0,1}
t_vec3	vec3_backward(void)
{
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = 1.0f});
}

/// returns a copy of vec
t_vec3	vec3_copy(t_vec3 vec)
{
	return (vec);
}

/// add the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

/// sub the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

/// div the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_div(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	return (result);
}
