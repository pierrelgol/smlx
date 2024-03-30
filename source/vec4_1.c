/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:38:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:38:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_vec4	vec4_create(float x, float y, float z, float w)
{
	return ((t_vec4){.x = x, .y = y, .z = z, .w = w});
}

t_vec4	vec4_create_rotation_x(float angle)
{
	float	half_angle;
	float	cos_half_angle;
	float	sin_half_angle;

	half_angle = angle / 2.0f;
	sin_half_angle = sinf(half_angle);
	cos_half_angle = cosf(half_angle);
	return ((t_vec4){.x = sin_half_angle, .y = 0.0f, .z = 0.0f,
		.w = cos_half_angle});
}

t_vec4	vec4_create_rotation_y(float angle)
{
	float	half_angle;
	float	cos_half_angle;
	float	sin_half_angle;

	half_angle = angle / 2.0f;
	sin_half_angle = sinf(half_angle);
	cos_half_angle = cosf(half_angle);
	return ((t_vec4){.x = 0.0f, .y = sin_half_angle, .z = 0.0f,
		.w = cos_half_angle});
}

t_vec4	vec4_create_rotation_z(float angle)
{
	float	half_angle;
	float	cos_half_angle;
	float	sin_half_angle;

	half_angle = angle / 2.0f;
	sin_half_angle = sinf(half_angle);
	cos_half_angle = cosf(half_angle);
	return ((t_vec4){.x = 0.0f, .y = 0.0f, .z = sin_half_angle,
		.w = cos_half_angle});
}

void	vec4_normalize_w(t_vec4 *q)
{
	float	magnitude;

	magnitude = sqrtf(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w);
	q->x /= magnitude;
	q->y /= magnitude;
	q->z /= magnitude;
	q->w /= magnitude;
}
