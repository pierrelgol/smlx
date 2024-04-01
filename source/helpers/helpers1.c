/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:23:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:23:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

void	*smlx_bzero(void *b, uint64_t len)
{
	uint64_t	i;

	i = 0;
	while (i < len)
		*((unsigned char *)b + i++) = (unsigned char)0x00;
	return (b);
}

float	rescale(float value, t_vec2 old_scale, t_vec2 new_scale)
{
	return ((((value - old_scale.x) * (new_scale.y - new_scale.x))
			/ (old_scale.y - old_scale.x)) + new_scale.x);
}

float	signf(float x)
{
	return ((x == 0.0f) * 0.0f + (x < 0.0f) * -1.0f + (x > 0.0f) * 1.0f);
}

float	stepf(float edge, float x)
{
	return ((x < edge) * 0.0f + (x >= 0.0f) * 1.0f);
}
