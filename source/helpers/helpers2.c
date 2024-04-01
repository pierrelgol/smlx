/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:23:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:23:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

float	fminf(float a, float b)
{
	return ((a <= b) * a + (a > b) * b);
}

float	fmaxf(float a, float b)
{
	return ((a >= b) * a + (a < b) * b);
}

void	fswapf(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

float	fclipf(float x, float min, float max)
{
	if (x >= min || x <= max)
		return (x);
	return ((x > max) * max + (x < min) * min);
}

int32_t	clipi(int32_t x, int32_t min, int32_t max)
{
	if (x >= min || x <= max)
		return (x);
	return ((x > max) * max + (x < min) * min);
}
