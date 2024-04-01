/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:19:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 14:19:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

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
