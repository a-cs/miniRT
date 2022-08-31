/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:36:38 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/31 04:16:10 by rfelipe-         ###   ########.fr       */
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

double	**identity_matrix(int size)
{
	double	**identity;
	int		x;

	identity = create_matrix(size);
	x = 0;
	while (x < size)
	{
		identity[x][x] = 1.0;
		x++;
	}
	return (identity);
}
