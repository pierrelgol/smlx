/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:55:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/31 14:55:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

/// creates a t_vec4 with value x, y, z and w
t_vec4	vec4_create(float x, float y, float z, float w)
{
	return ((t_vec4){.x = x, .y = y, .z = z, .w = w});
}

/// creates a t_vec3 from a t_vec4 with value x, y, z (drop the w)
t_vec3	vec4_to_vec3(t_vec4 v1)
{
	return ((t_vec3){.x = v1.x, .y = v1.y, .z = v1.z});
}

/// creates a t_vec4 from a t_vec3 with value x,.w = y, z, w
t_vec4	vec4_from_vec3(t_vec3 v1, float w)
{
	return ((t_vec4){.x = v1.x, .y = v1.y, .z = v1.z, .w = w});
}

/// creates a t_vec4 with value x, y, z and w set to 1.0f
t_vec4	vec4_create_1(void)
{
	return ((t_vec4){.x = 1.0f, .y = 1.0f, .z = 1.0f, .w = 1.0f});
}

/// creates a t_vec4 with value x, y, z and w set to 0.0f
t_vec4	vec4_create_0(void)
{
	return ((t_vec4){.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f});
}

/// add and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_add(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	result.w = v1.w + v2.w;
	return (result);
}

/// sub and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_sub(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	result.w = v1.w - v2.w;
	return (result);
}

/// div and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_div(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	result.w = v1.w / v2.w;
	return (result);
}

/// div the x, y, z, and w of v1 by scalar and returns the result
t_vec4	vec4_div_scalar(t_vec4 v1, float scalar)
{
	t_vec4	result;

	result.x = v1.x / scalar;
	result.y = v1.y / scalar;
	result.z = v1.z / scalar;
	result.w = v1.w / scalar;
	return (result);
}

/// mult and the x, y, z, and w of v1 and v2 and returns the result
t_vec4	vec4_mult(t_vec4 v1, t_vec4 v2)
{
	t_vec4	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	result.w = v1.w * v2.w;
	return (result);
}

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

/// compare all elements of v0 and v1 and ensure the difference is less than tolerance
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
