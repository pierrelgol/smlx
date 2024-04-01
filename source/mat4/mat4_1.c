/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:25:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:25:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns a "default" matrix
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
t_mat4x4	mat4_create(void)
{
	t_mat4x4	m;

	smlx_bzero(m.data, sizeof(float) * 16);
	return (m);
}

/// returns a "default" matrix
/// {1, 0, 0, 0}
/// {0, 1, 0, 0}
/// {0, 0, 1, 0}
/// {0, 0, 0, 1}
t_mat4x4	mat4_identity(void)
{
	t_mat4x4	m;

	smlx_bzero(m.data, sizeof(float) * 16);
	m.data[0] = 1.0f;
	m.data[5] = 1.0f;
	m.data[10] = 1.0f;
	m.data[15] = 1.0f;
	return (m);
}

/// returns the result of multiplying matrix m1 and m2
t_mat4x4	mat4_mult(t_mat4x4 m1, t_mat4x4 m2)
{
	t_mat4x4	out;
	float		*dst_ptr;
	float		*m1_ptr;
	uint32_t	i;
	uint32_t	j;

	out = mat4_identity();
	dst_ptr = out.data;
	m1_ptr = m1.data;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*dst_ptr = m1_ptr[0] * m2.data[0 + j] + m1_ptr[1] * m2.data[4 + j]
				+ m1_ptr[2] * m2.data[8 + j] + m1_ptr[3] * m2.data[12 + j];
			++dst_ptr;
			++j;
		}
		m1_ptr += 4;
		++i;
	}
	return (out);
}

/// returns an ortographic projection matrix
/// lrb is for (left, right, bottom)
/// tnf is for (top, near_clip, far_clip)
t_mat4x4	mat4_orthographic(t_vec3 lrb, t_vec3 tnf)
{
	t_mat4x4	out;
	float		lr;
	float		bt;
	float		nf;

	lr = 1.0f / (lrb.x - lrb.y);
	bt = 1.0f / (lrb.z - tnf.x);
	nf = 1.0f / (tnf.y - tnf.z);
	out = mat4_identity();
	out.data[0] = -2.0f * lr;
	out.data[5] = -2.0f * bt;
	out.data[10] = -2.0f * nf;
	out.data[12] = (lrb.x + lrb.y) * lr;
	out.data[13] = (tnf.x + lrb.z) * bt;
	out.data[14] = (tnf.z + tnf.y) * nf;
	return (out);
}

/// returns an perspective projection matrix
// t_vec2 fov_ar (fov_rad, aspect_ratio)
// t_vec2 nc_fc (near_clip, far_clip)
t_mat4x4	mat4_perspective(t_vec2 fov_ar, t_vec2 nc_fc)
{
	t_mat4x4	out;
	float		half_tan_fov;

	half_tan_fov = tanf(fov_ar.x * 0.5f);
	out = mat4_create();
	out.data[0] = 1.0f / (fov_ar.y * half_tan_fov);
	out.data[5] = 1.0f / half_tan_fov;
	out.data[10] = -((nc_fc.y + nc_fc.x) / (nc_fc.y - nc_fc.x));
	out.data[11] = -1.0f;
	out.data[14] = -((2.0f * nc_fc.y * nc_fc.x) / (nc_fc.y - nc_fc.x));
	return (out);
}
