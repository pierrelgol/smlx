/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:55:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 13:55:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_color color_create(char r, char g, char b, char a)
{
	t_color color;

	color = 0;
	color |= ((uint32_t) r) << 24;
	color |= ((uint32_t) g) << 16;
	color |= ((uint32_t) b) << 8;
	color |= ((uint32_t) a);
	return (color);
}

t_color color_adjust_lerp(t_color start, t_color end, float dist)
{
	t_color color;
	uint8_t s[4];
	uint8_t e[4];
	uint8_t r[4];

	s[0] = (start >> 24) & 0xFF;
	s[1] = (start >> 16) & 0xFF;
	s[2] = (start >> 8) & 0xFF;
	s[3] = start & 0xFF;
	e[0] = (end >> 24) & 0xFF;
	e[1] = (end >> 16) & 0xFF;
	e[2] = (end >> 8) & 0xFF;
	e[3] = end & 0xFF;
	r[0] = s[0] + (uint8_t) ((e[0] - s[0]) * dist);
	r[1] = s[1] + (uint8_t) ((e[1] - s[1]) * dist);
	r[2] = s[2] + (uint8_t) ((e[2] - s[2]) * dist);
	r[3] = s[3] + (uint8_t) ((e[3] - s[3]) * dist);
	color = (r[0] << 24) | (r[1] << 16) | (r[2] << 8) | r[3];
	return color;
}
