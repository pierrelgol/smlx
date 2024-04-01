/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:57:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 11:57:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

/// returns a default camera
t_camera camera_create(void)
{
	t_camera c;

	camera_reset(&c);
	return (c);
}

/// reset the current camera to the default value
void camera_reset(t_camera *c)
{
	if (c)
	{
		c->position = vec3_create_0();
		c->euler_rotation = vec3_create_0();
		c->is_dirty = false;
		c->view_matrix = mat4_identity();
	}
}

/// returns a copy of the current postion vector of the camera c
t_vec3 camera_position_get(t_camera *c)
{
	if (c)
		return (c->position);
	return (vec3_create_0());
}

/// sets the current postion vector of the camera c
void camera_position_set(t_camera *c, t_vec3 position)
{
	if (c)
	{
		c->position = position;
		c->is_dirty = true;
	}
}

/// returns a copy of the current euler_rotation vector of the camera c
t_vec3 camera_euler_rotation_get(t_camera *c)
{
	if (c)
		return (c->euler_rotation);
	return (vec3_create_0());
}

/// sets the current euler_rotation vector of the camera c
void camera_euler_rotation_set(t_camera *c, t_vec3 rotation)
{
	if (c)
	{
		c->euler_rotation.x = deg_to_rad(rotation.x);
		c->euler_rotation.y = deg_to_rad(rotation.y);
		c->euler_rotation.z = deg_to_rad(rotation.z);
		c->is_dirty = true;
	}
}

/// returns a copy of the current camera's view matrix
t_mat4x4 camera_view_matrix_get(t_camera *c)
{
	t_mat4x4 rotation;
	t_mat4x4 translation;

	if (c)
	{
		if (c->is_dirty)
		{
			rotation = mat4_euler_xyz(c->euler_rotation.x, c->euler_rotation.y, c->euler_rotation.z);
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
t_vec3 camera_forward(t_camera *c)
{
	t_mat4x4 view;

	if (c)
	{
		view = camera_view_matrix_get(c);	
		return (mat4_forward(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3 camera_backward(t_camera *c)
{
	t_mat4x4 view;

	if (c)
	{
		view = camera_view_matrix_get(c);	
		return (mat4_backward(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3 camera_left(t_camera *c)
{
	t_mat4x4 view;

	if (c)
	{
		view = camera_view_matrix_get(c);	
		return (mat4_left(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3 camera_right(t_camera *c)
{
	t_mat4x4 view;

	if (c)
	{
		view = camera_view_matrix_get(c);	
		return (mat4_right(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3 camera_up(t_camera *c)
{
	t_mat4x4 view;

	if (c)
	{
		view = camera_view_matrix_get(c);	
		return (mat4_up(view));
	}
	return (vec3_create_0());
}

/// returns a copy of the camera postion vector adjusted of a step
t_vec3 camera_down(t_camera *c)
{
	t_mat4x4 view;

	if (c)
	{
		view = camera_view_matrix_get(c);	
		return (mat4_down(view));
	}
	return (vec3_create_0());
}

/// moves the camera postin vector by the step
void camera_move_forward(t_camera *c, float amount)
{
	t_vec3 direction;

	if (c)
	{
		direction = camera_forward(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void camera_move_backward(t_camera *c, float amount)
{
	t_vec3 direction;

	if (c)
	{
		direction = camera_backward(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void camera_move_left(t_camera *c, float amount)
{
	t_vec3 direction;

	if (c)
	{
		direction = camera_left(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void camera_move_right(t_camera *c, float amount)
{
	t_vec3 direction;

	if (c)
	{
		direction = camera_right(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void camera_move_up(t_camera *c, float amount)
{
	t_vec3 direction;

	if (c)
	{
		direction = camera_up(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// moves the camera postin vector by the step
void camera_move_down(t_camera *c, float amount)
{
	t_vec3 direction;

	if (c)
	{
		direction = camera_down(c);
		direction = vec3_mult_scalar(direction, amount);
		c->position = vec3_add(c->position, direction);
		c->is_dirty = true;
	}
}

/// adjust the current camera's pitch by the amount given
void camera_pitch(t_camera *c, float amount)
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
void camera_yaw(t_camera *c, float amount)
{
	if (c)
	{
		c->euler_rotation.y += amount;
		c->is_dirty = true;
	}
}
