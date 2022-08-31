/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/31 04:26:00 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

// int	close_window(t_rtx *rtx)
// {
// 	mlx_destroy_window(rtx->mlx.ptr, rtx->mlx.window);
// 	rtx->mlx.window = NULL;
// 	ft_free_ptr((void *)&rtx->mlx.window);
// 	mlx_destroy_display(rtx->mlx.ptr);
// 	ft_free_ptr((void *)&rtx->mlx.ptr);
// 	if (rtx->world)
// 		ft_lstclear(&rtx->world, free);
// 	exit(0);
// }

// int	key_hooks(int key, t_rtx *rtx)
// {
// 	if (key == ESC)
// 		close_window(rtx);
// 	return (0);
// }

int	main(void)
{
	// t_rtx	rtx;

	double	**a;
	double	**b;
	double	**m;
	int		size = 4;
	a = create_matrix(size);
	b = create_matrix(size);

	a[0][0] = 0.0;
	a[0][1] = 9.0;
	a[0][2] = 3.0;
	a[0][3] = 0.0;
	a[1][0] = 9.0;
	a[1][1] = 8.0;
	a[1][2] = 0.0;
	a[1][3] = 8.0;
	a[2][0] = 1.0;
	a[2][1] = 8.0;
	a[2][2] = 5.0;
	a[2][3] = 3.0;
	a[3][0] = 0.0;
	a[3][1] = 0.0;
	a[3][2] = 5.0;
	a[3][3] = 8.0;
	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[0][3] = 4.0;
	b[1][0] = 1.0;
	b[1][1] = 2.0;
	b[1][2] = 4.0;
	b[1][3] = 8.0;
	b[2][0] = 2.0;
	b[2][1] = 4.0;
	b[2][2] = 8.0;
	b[2][3] = 16.0;
	b[3][0] = 4.0;
	b[3][1] = 8.0;
	b[3][2] = 16.0;
	b[3][3] = 32.0;
	// m = matrix_multiply(a, b, 4);
	m = matrix_transpose(a, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf ("[%.2f] ", m[i][j]);
		printf("\n");
	}
	// initiate_rtx(&rtx);
	// calculate(&rtx);
	// rtx.mlx.ptr = mlx_init();
	// if (rtx.mlx.ptr == NULL)
	// 	return (1);
	// rtx.mlx.window = mlx_new_window(rtx.mlx.ptr,
	// 		WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	// mlx_hook(rtx.mlx.window, 17, 0, &close_window, &rtx);
	// mlx_hook(rtx.mlx.window, 2, 1L << 0, key_hooks, &rtx);
	// mlx_loop_hook(rtx.mlx.ptr, &render, &rtx);
	// mlx_loop(rtx.mlx.ptr);
	ft_free_double_matrix(a, size);
	ft_free_double_matrix(b, size);
	ft_free_double_matrix(m, size);
	return (0);
}
