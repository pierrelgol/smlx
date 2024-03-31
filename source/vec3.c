/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:15:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/31 14:15:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

/// creates a t_vec3 with value x, y and z
t_vec3	vec3_create(float x, float y, float z)
{
	return ((t_vec3){x, y, z});
}

/// returns a t_vec3 from a t_vec4 with (x, y z) (drop w)
t_vec3	vec3_from_vec4(t_vec4 v1)
{
	return ((t_vec3){v1.x, v1.y, v1.z});
}

/// returns a t_vec4 from a t_vec3 with (x, y z, w)
t_vec4	vec3_to_vec4(t_vec3 v1, float w)
{
	return ((t_vec4){v1.x, v1.y, v1.z, w});
}

/// creates a t_vec3 with value x, y and z set to 1.0f
t_vec3	vec3_create_1(void)
{
	return ((t_vec3){1.0f, 1.0f, 1.0f});
}

/// creates a t_vec3 with value x, y and z set to 0.0f
t_vec3	vec3_create_0(void)
{
	return ((t_vec3){0.0f, 0.0f, 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,1,0}
t_vec3	vec3_up(void)
{
	return ((t_vec3){0.0f, 1.0f, 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,-1,0}
t_vec3	vec3_down(void)
{
	return ((t_vec3){0.0f, -1.0f, 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {-1,0,0}
t_vec3	vec3_left(void)
{
	return ((t_vec3){-1.0f, 0.0f, 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {1,0,0}
t_vec3	vec3_right(void)
{
	return ((t_vec3){1.0f, 0.0f, 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,0,-1}
t_vec3	vec3_forward(void)
{
	return ((t_vec3){0.0f, 0.0f, -1.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,0,1}
t_vec3	vec3_backward(void)
{
	return ((t_vec3){0.0f, 0.0f, 1.0f});
}

/// returns a copy of vec
t_vec3	vec3_copy(t_vec3 vec)
{
	return (vec);
}

/// add the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

/// sub the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

/// div the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_div(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	return (result);
}

/// mult the x, y and z of v1 and v2 and returns the result
t_vec3	vec3_mult(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

/// mult the x, y and z of v1 with a scalar and returns the result
t_vec3	vec3_mult_scalar(t_vec3 v1, float scalar)
{
	t_vec3	result;

	result.x = v1.x * scalar;
	result.y = v1.y * scalar;
	result.z = v1.z * scalar;
	return (result);
}

/// returns the result of x * x + y * y + z * z
float	vec3_len_square(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

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

	p += v1.x * v2.x;
	p += v1.y * v2.y;
	p += v1.z * v2.z;
	return (p);
}

/// returns the cross product between v1 and v2 ak the othogonal vectors to v1 and v2
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

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
