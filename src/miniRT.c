/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/08 23:10:14 by acarneir         ###   ########.fr       */
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
	t_vec	v;
	int		size = 4;
	// a = create_matrix(size);
	// b = create_matrix(size);
	// a[0][0] = 1;
	// a[0][1] = 2;
	// a[0][2] = 3;
	// a[0][3] = 4;
	// a[1][0] = 4;
	// a[1][1] = 3;
	// a[1][2] = 2;
	// a[1][3] = 1;
	// a[2][0] = 1;
	// a[2][1] = 2;
	// a[2][2] = 3;
	// a[2][3] = 4;
	// a[3][0] = 4;
	// a[3][1] = 3;
	// a[3][2] = 2;
	// a[3][3] = 1;
	a = m_rotate_z(0.25);
	printf("a = \n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf ("[%.2f] ", a[i][j]);
		printf("\n");
	}
	printf ("det a = %.2f\n", m_det(a, size));
	v = create_vector(0, 1, 0, 0);
	printf("v1 = {%.2f, %.2f, %.2f, %.2f}\n", v.x, v.y, v.z, v.w);
	v = multiply_m_v(a, v);
	printf("v2 = {%.2f, %.2f, %.2f, %.2f}\n", v.x, v.y, v.z, v.w);
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
