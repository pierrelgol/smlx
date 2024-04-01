/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:25:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 12:25:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

static void	projection_matrix_choose(t_view *v, t_matproj_type choice)
{
	t_vec3	param1;
	t_vec3	param2;
	t_vec2	param1s;
	t_vec2	param2s;

	if (v)
	{
		if (choice == PROJECT_ORTHO)
		{
			param1 = vec3_create(v->rect.x, v->rect.width, v->rect.height);
			param2 = vec3_create(v->rect.y, v->near_clip, v->far_clip);
			v->projection = mat4_orthographic(param1, param2);
		}
		else if (choice == PROJECT_PERSP)
		{
			param1s = vec2_create(v->fov, v->rect.width / v->rect.height);
			param2s = vec2_create(v->near_clip, v->far_clip);
			v->projection = mat4_perspective(param1s, param2s);
		}
		else
		{
			v->type = PROJECT_ORTHO;
			projection_matrix_choose(v, PROJECT_ORTHO);
		}
	}
}

void	view_create(t_vec4 rect, t_vec3 param, t_matproj_type type, t_view *out)
{
	out->rect = rect;
	out->fov = param.x;
	out->near_clip = param.y;
	out->far_clip = param.z;
	out->type = type;
	projection_matrix_choose(out, type);
}

void	view_resize(t_view *v, t_vec4 rect)
{
	if (v)
	{
		v->rect = rect;
		projection_matrix_choose(v, v->type);
	}
}

void	view_destroy(t_view *v)
{
	if (v)
	{
		smlx_bzero(v, sizeof(t_view));
	}
}
