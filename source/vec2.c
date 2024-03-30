/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:21:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:21:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

void	vec2_mult_scalar(t_vec2 *vec, float scalar)
{
	vec->x *= scalar;
	vec->y *= scalar;
}

void	vec2_mult_vec2(t_vec2 *a, t_vec2 *b, t_vec2 *c)
{
	c->x = a->x * b->x;
	c->y = a->y * b->y;
}

void	vec2_rot(t_vec2 *a, t_vec2 *r, t_vec2 *c)
{
	c->x = a->x * r->x - a->y * r->y;
	c->y = a->x * r->y + a->y * r->x;
}
