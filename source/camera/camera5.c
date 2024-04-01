/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:20:36 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:20:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// moves the camera postin vector by the step
void	camera_move_right(t_camera *c, float amount)
{
	t_vec3	direction;

	if (c)
	{
		direction = camera_right(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void	camera_move_up(t_camera *c, float amount)
{
	t_vec3	direction;

	if (c)
	{
		direction = camera_up(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void	camera_move_down(t_camera *c, float amount)
{
	t_vec3	direction;

	if (c)
	{
		direction = camera_down(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// adjust the current camera's pitch by the amount given
void	camera_pitch(t_camera *c, float amount)
{
	float	limit;

	if (c)
	{
		limit = 1.55334306f;
		c->euler_rotation.x += amount;
		c->euler_rotation.x = fclipf(c->euler_rotation.x, -limit, limit);
		c->is_dirty = true;
	}
}

/// adjust the current camera's yaw by the amount given
void	camera_yaw(t_camera *c, float amount)
{
	if (c)
	{
		c->euler_rotation.y += amount;
		c->is_dirty = true;
	}
}
