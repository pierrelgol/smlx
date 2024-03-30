/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:36:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 14:36:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_mat2x2	*mat2_create(t_allocator *allocator, t_vec2 a, t_vec2 b)
{
	t_mat2x2	*m;

	m = allocator->create(allocator, sizeof(t_mat2x2));
	m->m[0][0] = a.x;
	m->m[0][1] = b.x;
	m->m[1][0] = a.y;
	m->m[1][1] = b.y;
	return (m);
}

t_mat2x2	*mat2_create_rotation(t_allocator *allocator, float angle)
{
	t_mat2x2	*m;
	float		cos_angle;
	float		sin_angle;

	m = allocator->create(allocator, sizeof(t_mat2x2));
	sin_angle = sin(angle);
	cos_angle = cos(angle);
	m->m[0][0] = cos_angle;
	m->m[0][1] = -sin_angle;
	m->m[1][0] = sin_angle;
	m->m[1][1] = cos_angle;
	return (m);
}

void	mat2_mult_scalar(t_mat2x2 *m, float scalar)
{
	m->m[0][0] *= scalar;
	m->m[0][1] *= scalar;
	m->m[1][0] *= scalar;
	m->m[1][1] *= scalar;
}

void	mat2_mult_mat2(t_mat2x2 *a, t_mat2x2 *b, t_mat2x2 *c)
{
	c->m[0][0] = a->m[0][0] * b->m[0][0] + a->m[0][1] * b->m[1][0];
	c->m[0][1] = a->m[0][0] * b->m[0][1] + a->m[0][1] * b->m[1][1];
	c->m[1][0] = a->m[1][0] * b->m[0][0] + a->m[1][1] * b->m[1][0];
	c->m[1][1] = a->m[1][0] * b->m[0][1] + a->m[1][1] * b->m[1][1];
}

void	mat2_rot(t_mat2x2 *a, t_mat2x2 *r, t_mat2x2 *c)
{
	c->m[0][0] = a->m[0][0] * r->m[0][0] + a->m[0][1] * r->m[1][0];
	c->m[0][1] = a->m[0][0] * r->m[0][1] + a->m[0][1] * r->m[1][1];
	c->m[1][0] = a->m[1][0] * r->m[0][0] + a->m[1][1] * r->m[1][0];
	c->m[1][1] = a->m[1][0] * r->m[0][1] + a->m[1][1] * r->m[1][1];
}
