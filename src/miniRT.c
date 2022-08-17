/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/17 05:22:16 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	encode_rgb(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	render(t_mlx *mlx)
{
	int	x;
	int	y;
	int	*rgb;

	rgb = ft_calloc(3, sizeof(int));
	rgb[2] = 62;
	x = WINDOW_HEIGHT - 1;
	while (x >= 1)
	{
		rgb[1] = x;
		y = 1;
		while (y < WINDOW_WIDTH - 1)
		{
			rgb[0] = y;
			mlx_pixel_put(mlx->ptr, mlx->window, y, 256 - x,
				encode_rgb(rgb));
			y++;
		}
		x--;
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->window);
	mlx->window = NULL;
	mlx_destroy_display(mlx->ptr);
	exit(0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return (1);
	mlx.window = mlx_new_window(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	mlx_hook(mlx.window, 17, 0, &close_window, &mlx);
	mlx_loop_hook(mlx.ptr, &render, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
