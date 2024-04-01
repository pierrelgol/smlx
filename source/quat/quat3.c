/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:57:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:57:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

t_quat	quat_from_axis_angle(t_vec3 axis, float angle, bool normalize)
{
	t_quat	result;
	float	half_angle;
	float	sin;
	float	cos;

	half_angle = angle * 0.5;
	sin = sinf(half_angle);
	cos = cosf(half_angle);
	result = (t_quat){
		.x = sin * axis.x,
		.y = sin * axis.y,
		.z = sin * axis.z,
		.w = cos,
	};
	if (normalize)
		return (quat_normalized(result));
	return (result);
}

static t_quat	interpolate_quaternions(t_quat n1, t_quat n2, float dot,
		float p)
{
	float	theta_0;
	float	sin_theta;
	float	sin_theta_0;
	float	s0;
	float	s1;

	theta_0 = cosf(dot);
	sin_theta = sinf(theta_0 * p);
	sin_theta_0 = sinf(theta_0 * p);
	s0 = cosf(theta_0 * p) - dot * sin_theta / sin_theta_0;
	s1 = sin_theta / sin_theta_0;
	return ((t_quat){.x = (n1.x * s0) + (n2.x * s1), .y = (n1.y * s0) + (n2.y
			* s1), .z = (n1.z * s0) + (n2.z * s1), .w = (n1.w * s0) + (n2.w
			* s1)});
}

t_quat	quat_slerp(t_quat q1, t_quat q2, float p)
{
	t_quat	out;
	t_quat	n1;
	t_quat	n2;
	float	dot;

	n1 = quat_normalized(q1);
	n2 = quat_normalized(q2);
	dot = quat_dot(n1, n2);
	if (dot < 0.0f)
	{
		n1.x = -n1.x;
		n1.y = -n1.y;
		n1.z = -n1.z;
		n1.w = -n1.w;
		dot = -dot;
	}
	if (dot > 0.9995f)
	{
		out = (t_quat){.x = n1.x + ((n2.x - n1.x) * p), .y = n1.y + ((n2.y
					- n1.y) * p), .z = n1.z + ((n2.z - n1.z) * p), .w = n1.w
			+ ((n2.w - n1.w) * p)};
		return (quat_normalized(out));
	}
	return (interpolate_quaternions(n1, n2, dot, p));
}
