/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:03:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/31 14:03:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

/// creates a t_vec2 with value x and y
t_vec2	vec2_create(float x, float y)
{
	return ((t_vec2){.x = x, .y = y});
}

/// returns a t_vec2 from a t_vec3 (x, y)(drop z)
t_vec2	vec2_from_vec3(t_vec3 v1)
{
	return ((t_vec2){.x = v1.x, .y = v1.y});
}

/// returns a t_vec3 from a t_vec2 (x, y, z)
t_vec3	vec2_to_vec3(t_vec2 v1, float z)
{
	return ((t_vec3){.x = v1.x, .y = v1.y, .z = z});
}

/// creates a t_vec2 with value x and y set to 1.0f
t_vec2	vec2_create_1(void)
{
	return ((t_vec2){.x = 1.0f, .y = 1.0f});
}

/// creates a t_vec2 with value x and y set to 0.0f
t_vec2	vec2_create_0(void)
{
	return ((t_vec2){.x = 0.0f, .y = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,1}
t_vec2	vec2_up(void)
{
	return ((t_vec2){.x = 0.0f, .y = 1.0f});
}

/// creates a t_vec2 with value x, y and z set to {0,-1}
t_vec2	vec2_down(void)
{
	return ((t_vec2){.x = 0.0f, .y = -1.0f});
}

/// creates a t_vec2 with value x, y and z set to {-1,0}
t_vec2	vec2_left(void)
{
	return ((t_vec2){.x = -1.0f, .y = 0.0f});
}

/// creates a t_vec2 with value x, y and z set to {1,0}
t_vec2	vec2_right(void)
{
	return ((t_vec2){.x = 1.0f, .y = 0.0f});
}

/// returns a copy of vec
t_vec2	vec2_copy(t_vec2 vec)
{
	return (vec);
}

/// add the x and y of v1 and v2 and returns the result
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

/// sub the x and y of v1 and v2 and returns the result
t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return (result);
}

/// div the x and y of v1 and v2 and returns the result
t_vec2	vec2_div(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	return (result);
}

/// mult the x and y of v1 and v2 and returns the result
t_vec2	vec2_mult(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	return (result);
}

/// mult the x and y of v1 by scalar and returns the result
t_vec2	vec2_mult_scalar(t_vec2 v1, float scalar)
{
	return ((t_vec2){.x = v1.x * scalar, .y = v1.y * scalar});
}

/// mult the x and y of v1 and v2 and add v3 returns the result
t_vec2	vec2_mult_add(t_vec2 v1, t_vec2 v2, t_vec3 v3)
{
	return ((t_vec2){.x = v1.x * v2.x + v3.x, .y = v1.y * v2.y + v3.y});
}

/// returns the result of x * x + y * y
float	vec2_len_square(t_vec2 vec)
{
	return (vec.x * vec.x + vec.y * vec.y);
}

/// returns the result of sqrt(x * x + y * y)
float	vec2_length(t_vec2 vec)
{
	return (sqrtf(vec2_len_square(vec)));
}

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y))
/// vec->y / (sqrt(x * x + y * y))
void	vec2_normalize(t_vec2 *vec)
{
	float	len;

	len = vec2_length(*vec);
	vec->x /= len;
	vec->y /= len;
}

/// normalize vec with it's length and return the copy vec :
/// vec->x / (sqrt(x * x + y * y))
/// vec->y / (sqrt(x * x + y * y))
t_vec2	vec2_normalized(t_vec2 vec)
{
	vec2_normalize(&vec);
	return (vec);
}

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
