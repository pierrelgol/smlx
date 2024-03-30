/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:59:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 14:59:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_mat3x3	*mat3_create(t_allocator *allocator, t_vec3 a, t_vec3 b, t_vec3 c)
{
	t_mat3x3	*m;

	m = allocator->create(allocator, sizeof(t_mat3x3));
	m->m[0][0] = a.x;
	m->m[0][1] = b.x;
	m->m[0][2] = c.x;
	m->m[1][0] = a.y;
	m->m[1][1] = b.y;
	m->m[1][2] = c.y;
	m->m[2][0] = a.z;
	m->m[2][1] = b.z;
	m->m[2][2] = c.z;
	return (m);
}

t_mat3x3	*mat3_create_rotation(t_allocator *allocator, float angle)
{
	t_mat3x3	*m;
	float		cos_angle;
	float		sin_angle;

	m = allocator->create(allocator, sizeof(t_mat3x3));
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	m->m[0][0] = cos_angle;
	m->m[0][1] = -sin_angle;
	m->m[0][2] = 0.0f;
	m->m[1][0] = sin_angle;
	m->m[1][1] = cos_angle;
	m->m[1][2] = 0.0f;
	m->m[2][0] = 0.0f;
	m->m[2][1] = 0.0f;
	m->m[2][2] = 1.0f;
	return (m);
}

void	mat3_mult_scalar(t_mat3x3 *m, float scalar)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			m->m[i][j] *= scalar;
			++j;
		}
		++i;
	}
}

void	mat3_mult_mat3(t_mat3x3 *a, t_mat3x3 *b, t_mat3x3 *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			c->m[i][j] = a->m[i][0] * b->m[0][j] + a->m[i][1] * b->m[1][j] + a->m[i][2]
				* b->m[2][j];
			++j;
		}
		++i;
	}
}

void	mat3_rot(t_mat3x3 *a, t_mat3x3 *r, t_mat3x3 *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			c->m[i][j] = a->m[i][0] * r->m[0][j] + a->m[i][1] * r->m[1][j] + a->m[i][2]
				* r->m[2][j];
			++j;
		}
		++i;
	}
}
