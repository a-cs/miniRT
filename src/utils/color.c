/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:36:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/24 04:04:36 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	encode_rgb(t_vec3 color)
{
	return ((int)(color.x) << 16 | (int)(color.y) << 8 | (int)(color.z));
}

void	color_normalizer(int *rgb, double *norm_rgb)
{
	norm_rgb[0] = rgb[0] / 255.0;
	norm_rgb[1] = rgb[1] / 255.0;
	norm_rgb[2] = rgb[2] / 255.0;
}

void	color_unnormalizer(t_vec3 *norm_rgb, t_vec3 *rgb)
{
	rgb->x = (int)(norm_rgb->x * 255);
	rgb->y = (int)(norm_rgb->y * 255);
	rgb->z = (int)(norm_rgb->z * 255);
}

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
