/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:24:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:24:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns the result of sqrt(x * x + y * y + z * z)
float	vec3_length(t_vec3 vec)
{
	return (sqrtf(vec3_len_square(vec)));
}

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
void	vec3_normalize(t_vec3 *vec)
{
	float	len;

	len = vec3_length(*vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
t_vec3	vec3_normalized(t_vec3 vec)
{
	vec3_normalize(&vec);
	return (vec);
}

/// returns the dot product between v1 and v2 (eg. difference in direction)
float	vec3_dot(t_vec3 v1, t_vec3 v2)
{
	float	p;

	p = 0;
	p += v1.x * v2.x;
	p += v1.y * v2.y;
	p += v1.z * v2.z;
	return (p);
}

/// returns the cross product between v1 and v2 aka
/// the othogonal vectors to v1 and v2
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}
