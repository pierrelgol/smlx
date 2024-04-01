/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:25:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:25:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns a vector containing the minimum (x,y,z) of v1,v2
t_vec3	vec3_min(t_vec3 v1, t_vec3 v2)
{
	return (vec3_create(fminf(v1.x, v2.x), fminf(v1.y, v2.y), fminf(v1.z,
				v2.z)));
}

/// returns a vector containing the maximum (x,y,z) of v1,v2
t_vec3	vec3_max(t_vec3 v1, t_vec3 v2)
{
	return (vec3_create(fmaxf(v1.x, v2.x), fmaxf(v1.y, v2.y), fmaxf(v1.z,
				v2.z)));
}

/// returns a vector containing the sign (x,y,z) of v1
t_vec3	vec3_sign(t_vec3 v1)
{
	return (vec3_create(signf(v1.x), signf(v1.y), signf(v1.z)));
}

/// returns a vector rotated by the quat q
t_vec3	vec3_rotate(t_vec3 v1, t_quat q)
{
	t_vec3	u;
	float	s;

	u = vec3_create(q.x, q.y, q.z);
	s = q.w;
	return (vec3_add(vec3_add(vec3_mult_scalar(u, 2.0f * vec3_dot(u, v1)),
				vec3_mult_scalar(v1, (s * s - vec3_dot(u, u)))),
			vec3_mult_scalar(vec3_cross(u, v1), 2.0f * s)));
}
