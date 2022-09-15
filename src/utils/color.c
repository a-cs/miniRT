/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:36:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/15 03:50:30 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_color	vector_to_color(t_vec vec)
{
	t_color	color;

	color.r = vec.x;
	color.g = vec.y;
	color.b = vec.z;
	return (color);
}

int	encode_rgb(t_color color)
{
	return ((int)(color.r) << 16 | (int)(color.g) << 8 | (int)(color.b));
}

void	color_normalizer(int *rgb, double *norm_rgb)
{
	norm_rgb[0] = rgb[0] / 255.0;
	norm_rgb[1] = rgb[1] / 255.0;
	norm_rgb[2] = rgb[2] / 255.0;
}

void	color_unnormalizer(t_color *norm_rgb, t_color *rgb)
{
	rgb->r = (int)(norm_rgb->r * 255);
	rgb->g = (int)(norm_rgb->g * 255);
	rgb->b = (int)(norm_rgb->b * 255);
}

int	render(t_rtx *rtx)
{
	int	x;
	int	y;

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

t_vec	color_to_vector(t_color color)
{
	t_vec	vec;

	vec.x = color.r;
	vec.y = color.g;
	vec.z = color.b;
	vec.w = 0;
	return (vec);
}
