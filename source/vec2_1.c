/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:42:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:43:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_vec2	vec2_create(float x, float y)
{
	return ((t_vec2){.x = x, .y = y});
}

t_vec2	vec2_create_rotation_x(float angle)
{
	float	cos_angle;

	cos_angle = cosf(angle);
	return ((t_vec2){.x = 1.0f, .y = cos_angle});
}

t_vec2	vec2_create_rotation_y(float angle)
{
	float	cos_angle;

	cos_angle = cosf(angle);
	return ((t_vec2){.x = cos_angle, .y = 1.0f});
}
