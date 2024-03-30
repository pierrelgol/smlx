/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:48:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 16:48:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/smlx.h"

#define HEIGHT 1080
#define WIDTH 1920

void	triangle_draw(t_triangle *t)

int main(void)
{
	t_smlx       container;
	t_camera	camera;
	int	bpp;
	int endian;
	int ls;

	container.mlx = mlx_init();
	container.win = mlx_new_window(container.mlx, WIDTH, HEIGHT, "triangle");
	container.img = mlx_new_image(container.mlx, WIDTH, HEIGHT);
	container.pixels = mlx_get_data_addr(container.img, &bpp, &ls, &endian);
	camera.ffov = 90;
	camera.fzfar = 100;
	camera.fznear = 10;
	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;

	t_pixel a;
	t_pixel b;

	a.x = 0;
	a.y = 0;
	a.color = 0xFF0000;

	b.x = 1920;
	b.y = 1080;
	b.color = 0x000000;
	draw_line(&a, &b, container.pixels, WIDTH);
	mlx_put_image_to_window(container.mlx, container.win, container.img, 0, 0);
	mlx_loop(container.mlx);


	return (0);
}
