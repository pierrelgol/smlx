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
t_vec3 vec3_create(float x, float y, float z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

/// returns a t_vec3 from a t_vec4 with (x, y z) (drop w)
t_vec3 vec3_from_vec4(t_vec4 v1)
{
	return ((t_vec3){.x = v1.x, .y = v1.y, .z = v1.z});
}

/// returns a t_vec4 from a t_vec3 with (x, y z, w)
t_vec4 vec3_to_vec4(t_vec3 v1, float w)
{
	return ((t_vec4){v1.x, v1.y, v1.z, w});
}

/// creates a t_vec3 with value x, y and z set to 1.0f
t_vec3 vec3_create_1(void)
{
	return ((t_vec3){.x = 1.0f, .y = 1.0f, .z = 1.0f});
}

/// creates a t_vec3 with value x, y and z set to 0.0f
t_vec3 vec3_create_0(void)
{
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,1,0}
t_vec3 vec3_up(void)
{
	return ((t_vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,-1,0}
t_vec3 vec3_down(void)
{
	return ((t_vec3){.x = 0.0f, .y = -1.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {-1,0,0}
t_vec3 vec3_left(void)
{
	return ((t_vec3){.x = -1.0f, .y = 0.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {1,0,0}
t_vec3 vec3_right(void)
{
	return ((t_vec3){.x = 1.0f, .y = 0.0f, .z = 0.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,0,-1}
t_vec3 vec3_forward(void)
{
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = -1.0f});
}

/// creates a t_vec3 with value x, y and z set to {0,0,1}
t_vec3 vec3_backward(void)
{
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = 1.0f});
}

/// returns a copy of vec
t_vec3 vec3_copy(t_vec3 vec)
{
	return (vec);
}

/// add the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

/// sub the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3 result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

/// div the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_div(t_vec3 v1, t_vec3 v2)
{
	t_vec3 result;

	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	return (result);
}

/// div the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_div_scalar(t_vec3 v1, float scalar)
{
	t_vec3 result;

	result.x = v1.x / scalar;
	result.y = v1.y / scalar;
	result.z = v1.z / scalar;
	return (result);
}

/// mult the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_mult(t_vec3 v1, t_vec3 v2)
{
	t_vec3 result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

/// mult the x, y and z of v1 with a scalar and returns the result
t_vec3 vec3_mult_scalar(t_vec3 v1, float scalar)
{
	t_vec3 result;

	result.x = v1.x * scalar;
	result.y = v1.y * scalar;
	result.z = v1.z * scalar;
	return (result);
}

/// mult the x, y and z of v1 and v2 then add x, y, z of v3 and returns the result
t_vec3 vec3_mult_add(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_vec3 result;

	result.x = v1.x * v2.x + v3.x;
	result.y = v1.y * v2.y + v3.y;
	result.z = v1.z * v2.z + v3.z;
	return (result);
}

/// returns the result of x * x + y * y + z * z
float vec3_len_square(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/// returns the result of sqrt(x * x + y * y + z * z)
float vec3_length(t_vec3 vec)
{
	return (sqrtf(vec3_len_square(vec)));
}

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
void vec3_normalize(t_vec3 *vec)
{
	float len;

	len = vec3_length(*vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
t_vec3 vec3_normalized(t_vec3 vec)
{
	vec3_normalize(&vec);
	return (vec);
}

/// returns the dot product between v1 and v2 (eg. difference in direction)
float vec3_dot(t_vec3 v1, t_vec3 v2)
{
	float p;

	p = 0;
	p += v1.x * v2.x;
	p += v1.y * v2.y;
	p += v1.z * v2.z;
	return (p);
}

/// returns the cross product between v1 and v2 ak the othogonal vectors to v1 and v2
t_vec3 vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3 result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool vec3_compare(t_vec3 v1, t_vec3 v2, float tolerance)
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
float vec3_distance(t_vec3 v1, t_vec3 v2)
{
	t_vec3 distance;

	distance.x = (v1.x - v2.x);
	distance.y = (v1.y - v2.y);
	distance.z = (v1.z - v2.z);
	return (vec3_length(distance));
}

/// returns the squared distance between v1 and ve
float vec3_distance_squared(t_vec3 v1, t_vec3 v2)
{
	t_vec3 distance;

	distance.x = v1.x - v2.x;
	distance.y = v1.y - v2.y;
	distance.z = v1.z - v2.z;
	return (vec3_len_square(distance));
}

/// transform v by m (pass 1.0f in w for pont and 0.0f for a direction)
t_vec3 vec3_transform(t_vec3 v, float w, t_mat4x4 m)
{
	t_vec3 out;
	float *e;

	e = m.data;
	out.x = v.x * e[0 + 0] + v.y * e[4 + 0] + v.z * e[8 + 0] + w * e[12 + 0];
	out.y = v.x * e[0 + 1] + v.y * e[4 + 1] + v.z * e[8 + 1] + w * e[12 + 1];
	out.z = v.x * e[0 + 2] + v.y * e[4 + 2] + v.z * e[8 + 2] + w * e[12 + 2];
	return (out);
}

/// returns a vector containing the minimum (x,y,z) of v1,v2
t_vec3 vec3_min(t_vec3 v1, t_vec3 v2)
{
	return (vec3_create(fminf(v1.x, v2.x), fminf(v1.y, v2.y), fminf(v1.z, v2.z)));
}

/// returns a vector containing the maximum (x,y,z) of v1,v2
t_vec3 vec3_max(t_vec3 v1, t_vec3 v2)
{
	return (vec3_create(fmaxf(v1.x, v2.x), fmaxf(v1.y, v2.y), fmaxf(v1.z, v2.z)));
}

/// returns a vector containing the sign (x,y,z) of v1
t_vec3 vec3_sign(t_vec3 v1)
{
	return (vec3_create(signf(v1.x), signf(v1.y), signf(v1.z)));
}

/// returns a vector rotated by the quat q
t_vec3 vec3_rotate(t_vec3 v1, t_quat q)
{
	t_vec3 u;
	float  s;

	u = vec3_create(q.x, q.y, q.z);
	s = q.w;
	return (vec3_add(
	    vec3_add(
	        vec3_mult_scalar(u, 2.0f * vec3_dot(u, v1)),
	        vec3_mult_scalar(v1, (s * s - vec3_dot(u, u)))),
	    vec3_mult_scalar(vec3_cross(u, v1), 2.0f * s)));
}
