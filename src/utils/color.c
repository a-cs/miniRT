/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:36:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/20 03:21:08 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	encode_rgb(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	color_normalizer(int *rgb, double *norm_rgb)
{
	norm_rgb[0] = rgb[0] / 255.0;
	norm_rgb[1] = rgb[1] / 255.0;
	norm_rgb[2] = rgb[2] / 255.0;
}

void	color_unnormalizer(double *norm_rgb, int *rgb)
{
	rgb[0] = (int)(norm_rgb[0] * 255);
	rgb[1] = (int)(norm_rgb[1] * 255);
	rgb[2] = (int)(norm_rgb[2] * 255);
	// printf("rgb: %d | %d | %d --- norm: %.4f | %.4f | %.4f\n", rgb[0], rgb[1], rgb[2], norm_rgb[0], norm_rgb[1], norm_rgb[2]);
}
