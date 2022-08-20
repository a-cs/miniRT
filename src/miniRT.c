/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/19 22:59:21 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	render(t_rtx *rtx)
{
	int		x;
	int		y;

	y = WINDOW_HEIGHT - 1;
	while (y >= 1)
	{
		x = 1;
		while (x < WINDOW_WIDTH - 1)
		{
			mlx_pixel_put(rtx->mlx.ptr, rtx->mlx.window, x, WINDOW_HEIGHT - y,
				rtx->maps.pixel_map[x][y]);
			x++;
		}
		y--;
	}
	return (0);
}

int	close_window(t_rtx *rtx)
{
	mlx_destroy_window(rtx->mlx.ptr, rtx->mlx.window);
	rtx->mlx.window = NULL;
	ft_free_ptr((void *)&rtx->mlx.window);
	mlx_destroy_display(rtx->mlx.ptr);
	ft_free_ptr((void *)&rtx->mlx.ptr);
	exit(0);
}

int	key_hooks(int key, t_rtx *rtx)
{
	if (key == ESC)
		close_window(rtx);
	return (0);
}

int	main(void)
{
	t_rtx	rtx;

	calculate(&rtx);
	rtx.mlx.ptr = mlx_init();
	if (rtx.mlx.ptr == NULL)
		return (1);
	rtx.mlx.window = mlx_new_window(rtx.mlx.ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	mlx_hook(rtx.mlx.window, 17, 0, &close_window, &rtx);
	mlx_hook(rtx.mlx.window, 2, 1L << 0, key_hooks, &rtx);
	mlx_loop_hook(rtx.mlx.ptr, &render, &rtx);
	mlx_loop(rtx.mlx.ptr);
	return (0);
}
