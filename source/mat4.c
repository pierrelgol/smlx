/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:03:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:03:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_mat4x4 *mat4_create(t_allocator *allocator, t_vec4 v[4])
{
	t_mat4x4 *m;

	m = allocator->create(allocator, sizeof(t_mat4x4));
	m->m[0][0] = v[0].x;
	m->m[0][1] = v[1].x;
	m->m[0][2] = v[2].x;
	m->m[0][3] = v[3].x;
	m->m[1][0] = v[0].y;
	m->m[1][1] = v[1].y;
	m->m[1][2] = v[2].y;
	m->m[1][3] = v[3].y;
	m->m[2][0] = v[0].z;
	m->m[2][1] = v[1].z;
	m->m[2][2] = v[2].z;
	m->m[2][3] = v[3].z;
	m->m[3][0] = v[0].w;
	m->m[3][1] = v[1].w;
	m->m[3][2] = v[2].w;
	m->m[3][3] = v[3].w;
	return (m);
}

t_mat4x4 *mat4_create_rotation(t_allocator *allocator, float angle, t_vec3 axis)
{
	t_mat4x4 *m;
	float     cos_angle;
	float     sin_angle;

	m = allocator->create(allocator, sizeof(t_mat4x4));
	sin_angle = sin(angle);
	cos_angle = cos(angle);
	m->m[0][0] = cos_angle + axis.x * axis.x * (1.0f - cos_angle);
	m->m[0][1] = axis.x * axis.y * (1.0f - cos_angle) - axis.z * sin_angle;
	m->m[0][2] = axis.x * axis.z * (1.0f - cos_angle) + axis.y * sin_angle;
	m->m[0][3] = 0.0f;
	m->m[1][0] = axis.y * axis.x * (1.0f - cos_angle) + axis.z * sin_angle;
	m->m[1][1] = cos_angle + axis.y * axis.y * (1.0f - cos_angle);
	m->m[1][2] = axis.y * axis.z * (1.0f - cos_angle) - axis.x * sin_angle;
	m->m[1][3] = 0.0f;
	m->m[2][0] = axis.z * axis.x * (1.0f - cos_angle) - axis.y * sin_angle;
	m->m[2][1] = axis.z * axis.y * (1.0f - cos_angle) + axis.x * sin_angle;
	m->m[2][2] = cos_angle + axis.z * axis.z * (1.0f - cos_angle);
	m->m[2][3] = 0.0f;
	m->m[3][0] = 0.0f;
	m->m[3][1] = 0.0f;
	m->m[3][2] = 0.0f;
	m->m[3][3] = 1.0f;
	return (m);
}

void mat4_mult_scalar(t_mat4x4 *m, float scalar)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->m[i][j] *= scalar;
			++j;
		}
		++i;
	}
}

void mat4_mult_mat4(t_mat4x4 *a, t_mat4x4 *b, t_mat4x4 *c)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c->m[i][j] = a->m[i][0] * b->m[0][j] + a->m[i][1] * b->m[1][j] + a->m[i][2] * b->m[2][j] + a->m[i][3] * b->m[3][j];
			++j;
		}
		++i;
	}
}

void mat4_rot(t_mat4x4 *a, t_mat4x4 *r, t_mat4x4 *c)
{
	int     i;
	int     j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c->m[i][j] = a->m[i][0] * r->m[0][j] + a->m[i][1] * r->m[1][j] + a->m[i][2] * r->m[2][j] + a->m[i][3] * r->m[3][j];
			++j;
		}
		++i;
	}
}
