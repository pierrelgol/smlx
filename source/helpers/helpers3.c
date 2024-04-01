/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:23:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:23:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

bool	float_compare(float f0, float f1)
{
	return (fabsf(f0 - f1) < S_FLOAT_EPSILON);
}

float	deg_to_rad(float degrees)
{
	return (degrees * S_DEG_TO_RAD_MULT);
}

float	rad_to_deg(float degrees)
{
	return (degrees * S_RAD_TO_DEG_MULT);
}

void	rgbu_to_u32(uint32_t r, uint32_t g, uint32_t b, uint32_t *out_u32)
{
	*out_u32 = (((r & 0x0FF) << 16) | ((g & 0x0FF) << 8) | (b & 0x0FF));
}

void	u32_to_rgbu(uint32_t rgbu, uint32_t *out_r, uint32_t *out_g,
		uint32_t *out_b)
{
	*out_r = (rgbu >> 16) & 0x0FF;
	*out_g = (rgbu >> 8) & 0x0FF;
	*out_b = (rgbu) & 0x0FF;
}
