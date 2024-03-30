/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:27:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 13:27:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_pixel pixel_create(t_vec2 pos, t_color color)
{
	return ((t_pixel){.x = roundf(pos.x), .y = roundf(pos.y), .color = color});
}

void pixel_put(t_pixel *pixel, char *out, uint screen_width)
{
	uint *dest;
	uint  offset;

	offset = pixel->x * sizeof(int) + (screen_width * sizeof(int) * pixel->y);
	dest = (uint *) (out + offset);
	*dest = pixel->color;
}

static float scale_pixel_grad(int num, int min, int max)
{
	return (1.0f) * (num) / (max - min) + 0.0f;
}

void draw_line(t_pixel *a, t_pixel *b, char *pix, uint screen_width)
{
	t_pixel temp;
	float   k;
	float   l;
	int     x;

	k = (float) (b->y - a->y) / (float) (b->x - a->x);
	l = a->y - k * a->x;
	x = a->x;
	while (x <= b->x)
	{
		float f = abs(b->x - x);
		temp.color = color_adjust_lerp(a->color, b->color, scale_pixel_grad(f,0, 1920));
		temp.x = x;
		temp.y = roundf(k * x + l);
		pixel_put(&temp, pix, screen_width);
		++x;
	}
}
