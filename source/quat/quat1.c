/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:56:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:56:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns a default quat {0,0,0,1f}
t_quat	quat_identify(void)
{
	return ((t_quat){.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 1.0f});
}

/// returns the normal of a quat
float	quat_normal(t_quat q)
{
	return (sqrtf(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w));
}

/// normalize the quat
void	quat_normalize(t_quat *q)
{
	float	n;

	n = quat_normal(*q);
	q->x /= n;
	q->y /= n;
	q->z /= n;
	q->w /= n;
}

/// returns a normalized copy of the quat
t_quat	quat_normalized(t_quat q)
{
	quat_normalize(&q);
	return (q);
}

/// returns the conjugate copy of the quat
t_quat	quat_conjugate(t_quat q)
{
	return ((t_quat){.x = -q.x, .y = -q.y, .z = -q.z, .w = q.w});
}
