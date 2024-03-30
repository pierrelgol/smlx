/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:31:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:31:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

void	vec3_mult_scalar(t_vec3 *vec, float scalar)
{
	vec->x *= scalar;
	vec->y *= scalar;
	vec->z *= scalar;
}

void	vec3_mult_vec3(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x * b->x;
	c->y = a->y * b->y;
	c->z = a->z * b->z;
}

void	vec3_rot_x(t_vec3 *a, t_vec3 *r, t_vec3 *c)
{
	c->x = a->x;
	c->y = a->y * r->y - a->z * r->z;
	c->z = a->y * r->z + a->z * r->y;
}

void	vec3_rot_y(t_vec3 *a, t_vec3 *r, t_vec3 *c)
{
	c->x = a->x * r->x + a->z * r->z;
	c->y = a->y;
	c->z = -a->x * r->z + a->z * r->x;
}

void	vec3_rot_z(t_vec3 *a, t_vec3 *r, t_vec3 *c)
{
	c->x = a->x * r->x - a->y * r->y;
	c->y = a->x * r->y + a->y * r->x;
	c->z = a->z;
}
