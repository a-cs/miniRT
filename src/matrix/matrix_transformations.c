/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:00:50 by acarneir          #+#    #+#             */
/*   Updated: 2022/09/08 22:08:12 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	**m_translation(double x, double y, double z)
{
	double	**m;

	m = identity_matrix(4);
	m[0][3] = x;
	m[1][3] = y;
	m[2][3] = z;
	return (m);
}
