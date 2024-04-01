/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:20:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/01 13:20:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/smlx.h"

/// returns a default camera
t_camera	camera_create(void)
{
	t_camera	c;

	camera_reset(&c);
	return (c);
}
