/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:20:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:20:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns a copy of the camera postion vector adjusted of a step
t_vec3	camera_up(t_camera *c)
{
	t_mat4x4	view;

	if (c)
	{
		view = camera_view_matrix_get(c);
		return (mat4_up(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3	camera_down(t_camera *c)
{
	t_mat4x4	view;

	if (c)
	{
		view = camera_view_matrix_get(c);
		return (mat4_down(view));
	}
	return (vec3_create_0());
}

/// moves the camera postin vector by the step
void	camera_move_forward(t_camera *c, float amount)
{
	t_vec3	direction;

	if (c)
	{
		direction = camera_forward(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void	camera_move_backward(t_camera *c, float amount)
{
	t_vec3	direction;

	if (c)
	{
		direction = camera_backward(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void	camera_move_left(t_camera *c, float amount)
{
	t_vec3	direction;

	if (c)
	{
		direction = camera_left(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}
