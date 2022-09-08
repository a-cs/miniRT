/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:58:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/07 20:54:38 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	**sub_matrix(double **m, int size, int row, int col)
{
	double	**sub_m;
	int		i;
	int		j;
	int		a;
	int		b;

	sub_m = create_matrix(size - 1);
	a = -1;
	i = 0;
	while (++a < size)
	{
		b = 0;
		j = 0;
		if (a != row)
		{
			while (b < size)
			{
				if (b != col)
					sub_m[i][j++] = m[a][b];
				b++;
			}
			i++;
		}
	}
	return (sub_m);
}

double	cofactor(double **m, int size, int row, int col)
{
	double	**sub_m;
	double	cofactor;

	sub_m = sub_matrix(m, size, row, col);
	cofactor = pow(-1.0, (row + 1 + col + 1)) * matrix_det(sub_m, size - 1);
	ft_free_double_matrix(sub_m, size - 1);
	return (cofactor);
}

double	matrix_det(double **m, int size)
{
	double	det;
	int		col;

	det = 0.0;
	if (size == 2)
	{
		det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}
	else
	{
		col = 0;
		while (col < size)
		{
			det += m[0][col] * cofactor(m, size, 0, col);
			col++;
		}
	}
	return (det);
}
