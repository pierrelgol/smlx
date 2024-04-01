/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:20:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:20:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns a copy of the current camera's view matrix
t_mat4x4	camera_view_matrix_get(t_camera *c)
{
	t_mat4x4	rotation;
	t_mat4x4	translation;

	if (c)
	{
		if (c->is_dirty)
		{
			rotation = mat4_euler_xyz(c->euler_rotation.x, c->euler_rotation.y,
					c->euler_rotation.z);
			translation = mat4_translation(c->position);
			c->view_matrix = mat4_mult(rotation, translation);
			c->view_matrix = mat4_inverse(c->view_matrix);
			c->is_dirty = false;
		}
		return (c->view_matrix);
	}
	return (mat4_identity());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3	camera_forward(t_camera *c)
{
	t_mat4x4	view;

	if (c)
	{
		view = camera_view_matrix_get(c);
		return (mat4_forward(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3	camera_backward(t_camera *c)
{
	t_mat4x4	view;

	if (c)
	{
		view = camera_view_matrix_get(c);
		return (mat4_backward(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3	camera_left(t_camera *c)
{
	t_mat4x4	view;

	if (c)
	{
		view = camera_view_matrix_get(c);
		return (mat4_left(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3	camera_right(t_camera *c)
{
	t_mat4x4	view;

	if (c)
	{
		view = camera_view_matrix_get(c);
		return (mat4_right(view));
	}
	return (vec3_create_0());
}
