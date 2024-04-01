/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:19:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:19:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

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
