/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/24 22:50:44 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	close_window(t_rtx *rtx)
{
	mlx_destroy_window(rtx->mlx.ptr, rtx->mlx.window);
	rtx->mlx.window = NULL;
	ft_free_ptr((void *)&rtx->mlx.window);
	mlx_destroy_display(rtx->mlx.ptr);
	ft_free_ptr((void *)&rtx->mlx.ptr);
	if (rtx->world)
		ft_lstclear(&rtx->world, free);
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
