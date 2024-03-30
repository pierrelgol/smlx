/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:12:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 14:12:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

t_triangle *triangle_create(t_allocator *allocator, t_vec3 vertices[3])
{
	t_triangle *triangle;

	triangle = allocator->create(allocator, sizeof(t_triangle));
	vec3_copy(&triangle->v[0], &vertices[0]);
	vec3_copy(&triangle->v[1], &vertices[1]);
	vec3_copy(&triangle->v[2], &vertices[2]);
	return (triangle);
}

