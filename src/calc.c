/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:59:13 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/19 22:52:59 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	calculate(t_rtx *rtx)
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
			rtx->maps.pixel_map[x][y] = encode_rgb(rgb);
			x++;
		}
		y--;
	}
	free(rgb);
	free(norm_rgb);
}
