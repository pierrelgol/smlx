/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:39:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/31 18:39:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

float rescale(float value, t_vec2 old_scale, t_vec2 new_scale)
{
	return (((value - old_scale.x) * (new_scale.y - new_scale.x)) /
	        (old_scale.y - old_scale.x)) +
	       new_scale.x;
}

float signf(float x)
{
	return ((x == 0.0f) * 0.0f + (x < 0.0f) * -1.0f + (x > 0.0f) * 1.0f);
}

float stepf(float edge, float x)
{
	return ((x < edge) * 0.0f + (x >= 0.0f) * 1.0f);
}

float fminf(float a, float b)
{
	return ((a <= b) * a + (a > b) * b);
}

float fmaxf(float a, float b)
{
	return ((a >= b) * a + (a < b) * b);
}

void fswapf(float *a, float *b)
{
	float temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

float   fclipf(float x, float min, float max)
{
	if (x >= min || x <= max)
		return (x);
	return (x > max) * max + (x < min) * min;
}

int32_t clipi(int32_t x, int32_t min, int32_t max)
{
	if (x >= min || x <= max)
		return (x);
	return (x > max) * max + (x < min) * min;
}

bool float_compare(float f0, float f1)
{
	return (fabsf(f0 - f1) < S_FLOAT_EPSILON);
}

float deg_to_rad(float degrees)
{
	return (degrees * S_DEG_TO_RAD_MULT);
}

float rad_to_deg(float degrees)
{
	return (degrees * S_RAD_TO_DEG_MULT);
}

void rgbu_to_u32(uint32_t r, uint32_t g, uint32_t b, uint32_t *out_u32)
{
	*out_u32 = (((r & 0x0FF) << 16) | ((g & 0x0FF) << 8) | (b & 0x0FF));
}

void u32_to_rgbu(uint32_t rgbu, uint32_t *out_r, uint32_t *out_g, uint32_t *out_b)
{
	*out_r = (rgbu >> 16) & 0x0FF;
	*out_g = (rgbu >> 8) & 0x0FF;
	*out_b = (rgbu) & 0x0FF;
}
