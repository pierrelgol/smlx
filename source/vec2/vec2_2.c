/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:19:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:19:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// creates a t_vec3 with value x, y and z set to {0,1}
t_vec2	vec2_up(void)
{
	return ((t_vec2){.x = 0.0f, .y = 1.0f});
}

/// creates a t_vec2 with value x, y and z set to {0,-1}
t_vec2	vec2_down(void)
{
	return ((t_vec2){.x = 0.0f, .y = -1.0f});
}

/// creates a t_vec2 with value x, y and z set to {-1,0}
t_vec2	vec2_left(void)
{
	return ((t_vec2){.x = -1.0f, .y = 0.0f});
}

/// creates a t_vec2 with value x, y and z set to {1,0}
t_vec2	vec2_right(void)
{
	return ((t_vec2){.x = 1.0f, .y = 0.0f});
}

/// returns a copy of vec
t_vec2	vec2_copy(t_vec2 vec)
{
	return (vec);
}
