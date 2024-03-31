/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:36:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/31 17:36:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

/// returns a default quat {0,0,0,1f}
t_quat quat_identify(void)
{
	return ((t_quat){0.0f, 0.0f, 0.0f, 1.0f});
}

/// returns the normal of a quat
float quat_normal(t_quat q)
{
	return (sqrtf(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w));
}

/// normalize the quat
void quat_normalize(t_quat *q)
{
	float n;

	n = quat_normal(*q);
	q->x /= n;
	q->y /= n;
	q->z /= n;
	q->w /= n;
}

/// returns a normalized copy of the quat
t_quat quat_normalized(t_quat q)
{
	quat_normalize(&q);
	return (q);
}

/// returns the conjugate copy of the quat
t_quat quat_conjugate(t_quat q)
{
	return ((t_quat){-q.x, -q.y, -q.z, q.w});
}

/// returns the inverse copy of the quat
t_quat quat_inverse(t_quat q)
{
	return (quat_normalized(quat_conjugate(q)));
}

/// returns the result of the multiplication of q1 and q2
t_quat quat_mult(t_quat q1, t_quat q2)
{
	t_quat out;

	out.x = (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y) + (q1.w * q2.x);
	out.y = (-q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x) + (q1.w * q2.y);
	out.z = (q1.x * q2.y) - (q1.y * q2.x) + (q1.z * q2.w) + (q1.w * q2.z);
	out.w = -(q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z) + (q1.w * q2.w);
	return (out);
}

/// returns the dot product of q1 and q2
float quat_dot(t_quat q1, t_quat q2)
{
	return (q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w);
}

/// returns the rotation matrix of a rotation quaternion
t_mat4x4 *quat_to_mat4(t_allocator *allocator, t_quat q)
{
	t_mat4x4 *out;
	t_quat    n;

	out = mat4_identity(allocator);
	n = quat_normalized(q);
	out->elements[0] = 1.0f - 2.0f * n.y * n.y - 2.0f * n.z * n.z;
	out->elements[1] = 2.0f * n.x * n.y - 2.0f * n.z * n.w;
	out->elements[2] = 2.0f * n.x * n.z + 2.0f * n.y * n.w;

	out->elements[4] = 2.0f * n.x * n.y + 2.0f * n.z * n.w;
	out->elements[5] = 1.0f - 2.0f * n.x * n.x - 2.0f * n.z * n.z;
	out->elements[6] = 2.0f * n.y * n.z - 2.0f * n.x * n.w;

	out->elements[8] = 2.0f * n.x * n.z - 2.0f * n.y * n.w;
	out->elements[9] = 2.0f * n.y * n.z + 2.0f * n.x * n.w;
	out->elements[10] = 1.0f - 2.0f * n.x * n.x - 2.0f * n.y * n.y;
	return (out);
}

t_mat4x4 *quat_to_rotation_matrix(t_allocator *allocator, t_quat q, t_vec3 center)
{
	t_mat4x4 *out;
	float    *o;

	out = mat4_create(allocator);
	o = out->elements;
	o[0] = (q.x * q.x) - (q.y * q.y) - (q.z * q.z) + (q.w * q.w);
	o[1] = 2.0f * ((q.x * q.y) + (q.z * q.w));
	o[2] = 2.0f * ((q.x * q.z) - (q.y * q.w));
	o[3] = center.x - center.x * o[0] - center.y * o[1] - center.z * o[2];
	o[4] = 2.0f * ((q.x * q.y) - (q.z * q.w));
	o[5] = -(q.x * q.x) + (q.y * q.y) - (q.z * q.z) + (q.w * q.w);
	o[6] = 2.0f * ((q.y * q.z) + (q.x * q.w));
	o[7] = center.y - center.x * o[4] - center.y * o[5] - center.z * o[6];
	o[8] = 2.0f * ((q.x * q.z) + (q.y * q.w));
	o[9] = 2.0f * ((q.y * q.z) - (q.x * q.w));
	o[10] = -(q.x * q.x) - (q.y * q.y) + (q.z * q.z) + (q.w * q.w);
	o[11] = center.z - center.x * o[8] - center.y * o[9] - center.z * o[10];
	o[12] = 0.0f;
	o[13] = 0.0f;
	o[14] = 0.0f;
	o[15] = 1.0f;
	return (out);
}

t_quat quat_from_axis_angle(t_vec3 axis, float angle, bool normalize)
{
	t_quat result;
	float  half_angle;
	float  sin;
	float  cos;

	half_angle = angle * 0.5;
	sin = sinf(half_angle);
	cos = cosf(half_angle);
	result = (t_quat){sin * axis.x, sin * axis.y, sin * axis.z, cos};
	if (normalize)
		return (quat_normalized(result));
	return (result);
}
