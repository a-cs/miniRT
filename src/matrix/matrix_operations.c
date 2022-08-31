/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:58:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/31 03:40:13 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	**matrix_multiply(double **a, double **b, int size)
{
	int		row;
	int		col;
	int		x;
	double	**m;

	m = create_matrix(size);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			x = 0;
			while (x < size)
			{
				m[row][col] += a[row][x] * b[x][col];
				x++;
			}
			col++;
		}
		row++;
	}
	return (m);
}
