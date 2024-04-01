/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:27:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:27:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// mult the x, y, z, and w of v1 by scalar and returns the result
t_vec4	vec4_mult_scalar(t_vec4 v1, float scalar)
{
	t_vec4	result;

	result.x = v1.x * scalar;
	result.y = v1.y * scalar;
	result.z = v1.z * scalar;
	result.w = v1.w * scalar;
	return (result);
}

/// mult the x, y, z, and w of v1 by v2 and add v3 returns the result
t_vec4	vec4_mult_add(t_vec4 v1, t_vec4 v2, t_vec4 v3)
{
	t_vec4	result;

	result.x = v1.x * v2.x + v3.x;
	result.y = v1.y * v2.y + v3.y;
	result.z = v1.z * v2.z + v3.z;
	result.w = v1.w * v2.w + v3.w;
	return (result);
}

/// returns the result of x * x + y * y + z * z + w * w
float	vec4_len_square(t_vec4 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}

/// returns the result of sqrt(x * x + y * y + z * z + w * w)
float	vec4_length(t_vec4 vec)
{
	return (sqrtf(vec4_len_square(vec)));
}

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z + w * w))
/// vec->y / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
void	vec4_normalize(t_vec4 *vec)
{
	float	len;

	len = vec4_length(*vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
	vec->w /= len;
}
