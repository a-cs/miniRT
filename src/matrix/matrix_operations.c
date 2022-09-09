/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:58:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/08 21:49:26 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	**m_multiply(double **a, double **b, int size)
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

double	**m_transpose(double **a, int size)
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

double	**m_inverse(double **m, int size)
{
	int		row;
	int		col;
	double	det;
	double	**inv;

	det = m_det(m, size);
	if (det == 0)
		return (NULL);
	inv = create_matrix(size);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			inv[col][row] = cofactor(m, size, row, col) / det;
			col++;
		}
		row++;
	}
	return (inv);
}

t_vec	multiply_m_v(double **m, t_vec v)
{
	t_vec	new_v;

	new_v.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
	new_v.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
	new_v.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
	new_v.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;
	return (new_v);
}
