/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:47:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 15:47:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

void	vec2_copy(t_vec2 *dest, t_vec2 *source)
{
	dest->x = source->x;
	dest->y = source->y;
}

void vec2_add(t_vec2 *a, t_vec2 *b, t_vec2 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
}

void vec2_sub(t_vec2 *a, t_vec2 *b, t_vec2 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
}

int  vec2_comp(t_vec2 *a, t_vec2 *b, int(fn)(float a, float b))
{
	int	result[2];

	result[0] = fn(a->x, b->x);
	result[1] = fn(a->y, b->y);
	return (result[0] == 0 && result[1] == 0);
}

