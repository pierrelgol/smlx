/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:57:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:57:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

void vec3_copy(t_vec3 *dest, t_vec3 *source)
{
	dest->x = source->x;
	dest->y = source->y;
	dest->z = source->z;
}

void vec3_add(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
}

void vec3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
}

int vec3_comp(t_vec3 *a, t_vec3 *b, int(fn)(float a, float b))
{
	int result[3];

	result[0] = fn(a->x, b->x);
	result[1] = fn(a->y, b->y);
	result[2] = fn(a->z, b->z);
	return (result[0] == 0 && result[1] == 0 && result[2] == 0);
}
