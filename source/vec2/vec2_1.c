/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:19:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:19:09 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// creates a t_vec2 with value x and y
t_vec2	vec2_create(float x, float y)
{
	return ((t_vec2){.x = x, .y = y});
}

/// returns a t_vec2 from a t_vec3 (x, y)(drop z)
t_vec2	vec2_from_vec3(t_vec3 v1)
{
	return ((t_vec2){.x = v1.x, .y = v1.y});
}

/// returns a t_vec3 from a t_vec2 (x, y, z)
t_vec3	vec2_to_vec3(t_vec2 v1, float z)
{
	return ((t_vec3){.x = v1.x, .y = v1.y, .z = z});
}

/// creates a t_vec2 with value x and y set to 1.0f
t_vec2	vec2_create_1(void)
{
	return ((t_vec2){.x = 1.0f, .y = 1.0f});
}

/// creates a t_vec2 with value x and y set to 0.0f
t_vec2	vec2_create_0(void)
{
	return ((t_vec2){.x = 0.0f, .y = 0.0f});
}
