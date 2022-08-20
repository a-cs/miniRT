/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/20 03:20:36 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	render(t_rtx *rtx)
{
	int		x;
	int		y;
	int		*rgb;
	double	*norm_rgb;

	rgb = ft_calloc(3, sizeof(int));
	norm_rgb = ft_calloc(3, sizeof(double));
	norm_rgb[2] = 62 / 255.0;
	y = WINDOW_HEIGHT - 1;
	while (y >= 1)
	{
		norm_rgb[1] = y / 255.0;
		x = 1;
		while (x < WINDOW_WIDTH - 1)
		{
			norm_rgb[0] = x / 255.0;
			color_unnormalizer(norm_rgb, rgb);
			mlx_pixel_put(rtx->mlx->ptr, rtx->mlx->window, x, 256 - y,
				encode_rgb(rgb));
			x++;
		}
		y--;
	}
	return (0);
}

int	close_window(t_rtx *rtx)
{
	mlx_destroy_window(rtx->mlx->ptr, rtx->mlx->window);
	rtx->mlx->window = NULL;
	mlx_destroy_display(rtx->mlx->ptr);
	free(rtx->mlx);
	free(rtx);
	exit(0);
}

int	main(void)
{
	t_rtx	*rtx;

	rtx = ft_calloc(1, sizeof(t_rtx));
	rtx->mlx->ptr = mlx_init();
	if (rtx->mlx->ptr == NULL)
		return (1);
	rtx->mlx->window = mlx_new_window(rtx->mlx->ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	mlx_hook(rtx->mlx->window, 17, 0, &close_window, rtx);
	mlx_loop_hook(rtx->mlx->ptr, &render, rtx);
	mlx_loop(rtx->mlx->ptr);
	return (0);
}
