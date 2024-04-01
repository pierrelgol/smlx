/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:22:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:22:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// creates a t_vec3 with value x, y and z set to {0,1,0}
t_vec3	vec3_up(void)
{
	return ((t_vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,-1,0}
t_vec3	vec3_down(void)
{
	return ((t_vec3){.x = 0.0f, .y = -1.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {-1,0,0}
t_vec3	vec3_left(void)
{
	return ((t_vec3){.x = -1.0f, .y = 0.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {1,0,0}
t_vec3	vec3_right(void)
{
	return ((t_vec3){.x = 1.0f, .y = 0.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,0,-1}
t_vec3	vec3_forward(void)
{
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = -1.0f});
}
