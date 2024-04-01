/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:20:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:20:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// reset the current camera to the default value
void	camera_reset(t_camera *c)
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
t_vec3	camera_position_get(t_camera *c)
{
	if (c)
		return (c->position);
	return (vec3_create_0());
}

/// sets the current postion vector of the camera c
void	camera_position_set(t_camera *c, t_vec3 position)
{
	if (c)
	{
		c->position = position;
		c->is_dirty = true;
	}
}

/// returns a copy of the current euler_rotation vector of the camera c
t_vec3	camera_euler_rotation_get(t_camera *c)
{
	if (c)
		return (c->euler_rotation);
	return (vec3_create_0());
}

/// sets the current euler_rotation vector of the camera c
void	camera_euler_rotation_set(t_camera *c, t_vec3 rotation)
{
	if (c)
	{
		c->euler_rotation.x = deg_to_rad(rotation.x);
		c->euler_rotation.y = deg_to_rad(rotation.y);
		c->euler_rotation.z = deg_to_rad(rotation.z);
		c->is_dirty = true;
	}
}
