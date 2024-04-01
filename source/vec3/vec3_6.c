/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:25:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:25:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool	vec3_compare(t_vec3 v1, t_vec3 v2, float tolerance)
{
	if (fabsf(v1.x - v2.x) > tolerance)
		return (false);
	if (fabsf(v1.y - v2.y) > tolerance)
		return (false);
	if (fabsf(v1.z - v2.z) > tolerance)
		return (false);
	return (true);
}

/// returns the distance between v1 and v2
float	vec3_distance(t_vec3 v1, t_vec3 v2)
{
	t_vec3	distance;

	distance.x = (v1.x - v2.x);
	distance.y = (v1.y - v2.y);
	distance.z = (v1.z - v2.z);
	return (vec3_length(distance));
}

/// returns the squared distance between v1 and ve
float	vec3_distance_squared(t_vec3 v1, t_vec3 v2)
{
	t_vec3	distance;

	distance.x = v1.x - v2.x;
	distance.y = v1.y - v2.y;
	distance.z = v1.z - v2.z;
	return (vec3_len_square(distance));
}

/// transform v by m (pass 1.0f in w for pont and 0.0f for a direction)
t_vec3	vec3_transform(t_vec3 v, float w, t_mat4x4 m)
{
	t_vec3	out;
	float	*e;

	e = m.data;
	out.x = v.x * e[0 + 0] + v.y * e[4 + 0] + v.z * e[8 + 0] + w * e[12 + 0];
	out.y = v.x * e[0 + 1] + v.y * e[4 + 1] + v.z * e[8 + 1] + w * e[12 + 1];
	out.z = v.x * e[0 + 2] + v.y * e[4 + 2] + v.z * e[8 + 2] + w * e[12 + 2];
	return (out);
}
