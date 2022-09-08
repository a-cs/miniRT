/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/07 20:52:31 by acarneir         ###   ########.fr       */
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
	// double	**b;
	// double	**m;
	int		size = 4;
	a = create_matrix(size);
	// b = create_matrix(size);
	a[0][0] = -2;
	a[0][1] = -8;
	a[0][2] = 3;
	a[0][3] = 5;
	a[1][0] = -3;
	a[1][1] = 1;
	a[1][2] = 7;
	a[1][3] = 3;
	a[2][0] = 1;
	a[2][1] = 2;
	a[2][2] = -9;
	a[2][3] = 6;
	a[3][0] = -6;
	a[3][1] = 7;
	a[3][2] = 7;
	a[3][3] = -9;
	printf("a = \n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf ("[%.2f] ", a[i][j]);
		printf("\n");
	}
	printf ("cof[0][0] = %.2f\n", cofactor(a, size, 0, 0));
	printf ("cof[0][1] = %.2f\n", cofactor(a, size, 0, 1));
	printf ("cof[0][2] = %.2f\n", cofactor(a, size, 0, 2));
	printf ("cof[0][3] = %.2f\n", cofactor(a, size, 0, 3));
	printf ("det a = %.2f\n", matrix_det(a, size));
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
	// ft_free_double_matrix(b, size);
	// ft_free_double_matrix(m, size);
	return (0);
}
