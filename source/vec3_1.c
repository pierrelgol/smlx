/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:39:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:39:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_vec3	vec3_create(float x, float y, float z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

t_vec3	vec3_create_rotation_x(float angle)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cosf(angle);
	sin_angle = sinf(angle);
	return ((t_vec3){.x = 1.0f, .y = cos_angle, .z = sin_angle});
}

t_vec3	vec3_create_rotation_y(float angle)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cosf(angle);
	sin_angle = sinf(angle);
	return ((t_vec3){.x = cos_angle, .y = 1.0f, .z = sin_angle});
}

t_vec3	vec3_create_rotation_z(float angle)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cosf(angle);
	sin_angle = sinf(angle);
	return ((t_vec3){.x = cos_angle, .y = sin_angle, .z = 1.0f});
}
