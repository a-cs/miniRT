/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:36:38 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/31 03:38:40 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	**create_matrix(int size)
{
	double	**matrix;
	int		x;

	matrix = ft_calloc(size, sizeof(double *));
	x = 0;
	while (x < size)
	{
		matrix[x] = ft_calloc(size, sizeof(double));
		x++;
	}
	return (matrix);
}
