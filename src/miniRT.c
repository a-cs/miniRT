/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:06:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/17 22:26:22 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

// int	encode_rgb(int *rgb)
// {
// 	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
// }

// int	render(t_mlx *mlx)
// {
// 	int	x;
// 	int	y;
// 	int	*rgb;

// 	rgb = ft_calloc(3, sizeof(int));
// 	rgb[2] = 62;
// 	y = WINDOW_HEIGHT - 1;
// 	while (y >= 1)
// 	{
// 		rgb[1] = y;
// 		x = 1;
// 		while (x < WINDOW_WIDTH - 1)
// 		{
// 			rgb[0] = x;
// 			mlx_pixel_put(mlx->ptr, mlx->window, x, 256 - y,
// 				encode_rgb(rgb));
// 			x++;
// 		}
// 		y--;
// 	}
// 	return (0);
// }

// int	close_window(t_mlx *mlx)
// {
// 	mlx_destroy_window(mlx->ptr, mlx->window);
// 	mlx->window = NULL;
// 	mlx_destroy_display(mlx->ptr);
// 	exit(0);
// }

int	main(void)
{
	// t_mlx	mlx;

	// mlx.ptr = mlx_init();
	// if (mlx.ptr == NULL)
	// 	return (1);
	// mlx.window = mlx_new_window(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	// mlx_hook(mlx.window, 17, 0, &close_window, &mlx);
	// mlx_loop_hook(mlx.ptr, &render, &mlx);
	// mlx_loop(mlx.ptr);
	// t_vec3	a;
	t_vec3	b;
	double	n;
	// t_vec3	c;

	// a = create_vector(1, 2, 3);
	b = create_vector(4, 5, 6);
	n = vector_length(b);
	printf("n -> %f\n", n);
	return (0);
}
