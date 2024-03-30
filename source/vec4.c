/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:33:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:33:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

void	vec4_mult_scalar(t_vec4 *vec, float scalar)
{
	vec->x *= scalar;
	vec->y *= scalar;
	vec->z *= scalar;
	vec->w *= scalar;
}

void	vec4_mult_vec4(t_vec4 *a, t_vec4 *b, t_vec4 *c)
{
	c->x = a->x * b->x;
	c->y = a->y * b->y;
	c->z = a->z * b->z;
	c->w = a->w * b->w;
}

void	vec4_rot_x(t_vec4 *a, t_vec4 *r, t_vec4 *c)
{
	c->x = a->x;
	c->y = a->y * r->y - a->z * r->z;
	c->z = a->y * r->z + a->z * r->y;
	c->w = a->w;
}

void	vec4_rot_y(t_vec4 *a, t_vec4 *r, t_vec4 *c)
{
	c->x = a->x * r->x + a->z * r->z;
	c->y = a->y;
	c->z = -a->x * r->z + a->z * r->x;
	c->w = a->w;
}

void	vec4_rot_z(t_vec4 *a, t_vec4 *r, t_vec4 *c)
{
	c->x = a->x * r->x - a->y * r->y;
	c->y = a->x * r->y + a->y * r->x;
	c->z = a->z;
	c->w = a->w;
}
