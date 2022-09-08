/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:58:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/07 20:57:33 by acarneir         ###   ########.fr       */
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

double	**matrix_transpose(double **a, int size)
{
	int		row;
	int		col;
	double	**m;

	m = create_matrix(size);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			m[row][col] = a[col][row];
			col++;
		}
		row++;
	}
	return (m);
}
