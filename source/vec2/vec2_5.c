/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:21:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:21:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool	vec2_compare(t_vec2 v1, t_vec2 v2, float tolerance)
{
	if (fabsf(v1.x - v2.x) > tolerance)
		return (false);
	if (fabsf(v1.y - v2.y) > tolerance)
		return (false);
	return (true);
}

/// returns the distance between v1 and v2
float	vec2_distance(t_vec2 v1, t_vec2 v2)
{
	t_vec2	distance;

	distance.x = (v1.x - v2.x);
	distance.y = (v1.y - v2.y);
	return (vec2_length(distance));
}

/// returns the squared distance of v1 and v2 (avoid sqrt)
float	vec2_ditance_squared(t_vec2 v1, t_vec2 v2)
{
	t_vec2	distance;

	distance.x = (v1.x - v2.x);
	distance.y = (v1.y - v2.y);
	return (vec2_len_square(distance));
}
