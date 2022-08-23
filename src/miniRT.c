/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/23 01:08:21 by acarneir         ###   ########.fr       */
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

void	initiate_rtx(t_rtx *rtx)
{
	rtx->viewport_height = 2;
	rtx->viewport_width = 16.0 / 9.0 * rtx->viewport_height;
	rtx->focal_length = 1.0;
	rtx->origin = create_vector(0, 0, 0);
	rtx->horizontal = create_vector(rtx->viewport_width, 0, 0);
	rtx->vertical = create_vector(0, rtx->viewport_height, 0);
	rtx->lower_left_corner = vector_sub(rtx->origin,
			vector_add(vector_div(rtx->horizontal, 2.0), vector_add(
					vector_div(rtx->vertical, 2.0),
					create_vector(0.0, 0.0, rtx->focal_length))));
	// printf("llc.x = %f, llc.y = %f, llc.z = %f\n", rtx->lower_left_corner.x, rtx->lower_left_corner.y, rtx->lower_left_corner.z);
}

int	main(void)
{
	t_rtx	rtx;

	initiate_rtx(&rtx);
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
