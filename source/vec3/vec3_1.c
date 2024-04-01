/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:21:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:22:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// creates a t_vec3 with value x, y and z
t_vec3	vec3_create(float x, float y, float z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

/// returns a t_vec3 from a t_vec4 with (x, y z) (drop w)
t_vec3	vec3_from_vec4(t_vec4 v1)
{
	return ((t_vec3){.x = v1.x, .y = v1.y, .z = v1.z});
}

/// returns a t_vec4 from a t_vec3 with (x, y z, w)
t_vec4	vec3_to_vec4(t_vec3 v1, float w)
{
	return ((t_vec4){.x = v1.x, .y = v1.y, .z = v1.z, .w = w});
}

/// creates a t_vec3 with value x, y and z set to 1.0f
t_vec3	vec3_create_1(void)
{
	return ((t_vec3){.x = 1.0f, .y = 1.0f, .z = 1.0f});
}

/// creates a t_vec3 with value x, y and z set to 0.0f
t_vec3	vec3_create_0(void)
{
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = 0.0f});
}
