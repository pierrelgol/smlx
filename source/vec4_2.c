/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:57:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:57:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

void vec4_copy(t_vec4 *dest, t_vec4 *source)
{
	dest->x = source->x;
	dest->y = source->y;
	dest->z = source->z;
	dest->w = source->w;
}

void vec4_add(t_vec4 *a, t_vec4 *b, t_vec4 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
	c->w = a->w + b->w;
}

void vec4_sub(t_vec4 *a, t_vec4 *b, t_vec4 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
	c->w = a->w - b->w;
}

int vec4_comp(t_vec4 *a, t_vec4 *b, int(fn)(float a, float b))
{
	int result[4];

	result[0] = fn(a->x, b->x);
	result[1] = fn(a->y, b->y);
	result[2] = fn(a->z, b->z);
	result[3] = fn(a->w, b->w);
	return (result[0] == 0 && result[1] == 0 && result[2] == 0 && result[3] == 0);
}
