/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:27:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:27:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z + w * w))
/// vec->y / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
t_vec4	vec4_normalized(t_vec4 vec)
{
	vec4_normalize(&vec);
	return (vec);
}

/// returns the dot product of v1 and v2
float	vec4_dot(t_vec4 v1, t_vec4 v2)
{
	float	p;

	p = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	return (p);
}

/// compare all elements of v0 and v1 and ensure 
/// the difference is less than tolerance
bool	vec4_compare(t_vec4 v1, t_vec4 v2, float tolerance)
{
	if (fabsf(v1.x - v2.x) > tolerance)
		return (false);
	if (fabsf(v1.y - v2.y) > tolerance)
		return (false);
	if (fabsf(v1.z - v2.z) > tolerance)
		return (false);
	if (fabsf(v1.w - v2.w) > tolerance)
		return (false);
	return (true);
}
