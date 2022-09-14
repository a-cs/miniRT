/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:59:13 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/14 04:02:14 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	calculate(t_rtx *rtx)
{
	// int		i;
	// int		j;
	// double	u;
	// double	v;
	// t_ray	ray;
	// t_color	pixel_color;
	// t_color	pixel_color2;

	// j = WINDOW_HEIGHT - 1;
	// while (j >= 0)
	// {
	// 	i = 0;
	// 	while (i < WINDOW_WIDTH)
	// 	{
	// 		u = (double)(i) / (double)(WINDOW_WIDTH - 1.0);
	// 		v = (double)(j) / (double)(WINDOW_HEIGHT - 1.0);
	// 		// printf("u = %f, v = %f\n", u, v);
	// 		ray = create_ray(rtx->origin, vector_add(rtx->lower_left_corner,
	// 					vector_add(vector_mul_scal(rtx->horizontal, u),
	// 						vector_sub(vector_mul_scal(rtx->vertical, v),
	// 							rtx->origin))));
	// 		// printf("[%d][%d] ray.d.x = %f, ray.d.y = %f, ray.d.z = %f\n", i,j, ray.direction.x, ray.direction.y, ray.direction.z);
			// pixel_color = ray_color(rtx, ray);
	// 		// printf("p1.x = %f, p1.y = %f, p1.z = %f\n", pixel_color.x, pixel_color.y, pixel_color.z);
			// color_unnormalizer(&pixel_color, &pixel_color2);
	// 		// printf("p2.x = %f, p2.y = %f, p2.z = %f\n", pixel_color2.x, pixel_color2.y, pixel_color2.z);
	// 		rtx->maps.pixel_map[i][j] = encode_rgb(pixel_color2);
	// 		i++;
	// 	}
	// 	j--;
	// }

	int		i;
	int		j;
	t_color	pixel_color;
	t_color	pixel_color2;
	t_ray	ray;
	double	u;
	double	v;

	pixel_color = vector_to_color(create_vector(255, 0, 0, 0));
	j = WINDOW_HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WINDOW_WIDTH - 1)
		{
			u = (double)(i) / (double)(WINDOW_WIDTH - 1.0);
			v = (double)(j) / (double)(WINDOW_HEIGHT - 1.0);
			ray = create_ray(rtx->origin, vector_add(rtx->lower_left_corner,
						vector_add(vector_mul_scal(rtx->horizontal, u),
							vector_sub(vector_mul_scal(rtx->vertical, v),
								rtx->origin))));
			pixel_color = ray_color(rtx, ray);
			color_unnormalizer(&pixel_color, &pixel_color2);
			rtx->maps.pixel_map[i][j] = encode_rgb(pixel_color2);
			i++;
		}
		j--;
	}
}
