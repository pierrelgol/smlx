/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:27:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:27:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// creates a t_vec4 with value x, y, z and w
t_vec4	vec4_create(float x, float y, float z, float w)
{
	return ((t_vec4){.x = x, .y = y, .z = z, .w = w});
}

/// creates a t_vec3 from a t_vec4 with value x, y, z (drop the w)
t_vec3	vec4_to_vec3(t_vec4 v1)
{
	return ((t_vec3){.x = v1.x, .y = v1.y, .z = v1.z});
}

/// creates a t_vec4 from a t_vec3 with value x,.w = y, z, w
t_vec4	vec4_from_vec3(t_vec3 v1, float w)
{
	return ((t_vec4){.x = v1.x, .y = v1.y, .z = v1.z, .w = w});
}

/// creates a t_vec4 with value x, y, z and w set to 1.0f
t_vec4	vec4_create_1(void)
{
	return ((t_vec4){.x = 1.0f, .y = 1.0f, .z = 1.0f, .w = 1.0f});
}

/// creates a t_vec4 with value x, y, z and w set to 0.0f
t_vec4	vec4_create_0(void)
{
	return ((t_vec4){.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f});
}
