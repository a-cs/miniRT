/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:59:13 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/21 23:13:51 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ray	ray_for_pixel(t_rtx *rtx, double px, double py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	double	**inverse;
	t_vec	pixel;
	t_vec	origin;
	t_vec	direction;
	t_ray	ray;

	xoffset = (px + 0.5) * rtx->pixel_size;
	yoffset = (py + 0.5) * rtx->pixel_size;
	world_x = (rtx->viewport_width / 2) - xoffset;
	world_y = (rtx->viewport_height / 2) - yoffset;
	inverse = m_inverse(rtx->cam_transform, 4);
	pixel = multiply_m_v(inverse, create_vector(world_x, world_y, 1, 1));
	origin = multiply_m_v(inverse, create_vector(0, 0, 0, 1));
	direction = unit_vector(vector_sub(pixel, origin));
	ray = create_ray(origin, direction);
	ft_free_double_matrix(inverse, 4);
	return (ray);
}

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
			ray = ray_for_pixel(rtx, u, v);
			pixel_color = ray_color(rtx, ray);
			color_unnormalizer(&pixel_color, &pixel_color2);
			rtx->maps.pixel_map[i][j] = encode_rgb(pixel_color2);
			i++;
		}
		j--;
	}
}
