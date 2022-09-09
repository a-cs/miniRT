/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:00:50 by acarneir          #+#    #+#             */
/*   Updated: 2022/09/08 23:07:30 by acarneir         ###   ########.fr       */
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

double	**m_scaling(double x, double y, double z)
{
	double	**m;

	m = identity_matrix(4);
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
	return (m);
}

double	**m_rotate_x(double n_angle)
{
	double	**m;
	double	rad;

	m = identity_matrix(4);
	rad = n_angle * M_PI;
	m[1][1] = cos(rad);
	m[1][2] = -sin(rad);
	m[2][1] = sin(rad);
	m[2][2] = cos(rad);
	return (m);
}

double	**m_rotate_y(double n_angle)
{
	double	**m;
	double	rad;

	m = identity_matrix(4);
	rad = n_angle * M_PI;
	m[0][0] = cos(rad);
	m[0][2] = sin(rad);
	m[2][0] = -sin(rad);
	m[2][2] = cos(rad);
	return (m);
}

double	**m_rotate_z(double n_angle)
{
	double	**m;
	double	rad;

	m = identity_matrix(4);
	rad = n_angle * M_PI;
	m[0][0] = cos(rad);
	m[0][1] = -sin(rad);
	m[1][0] = sin(rad);
	m[1][1] = cos(rad);
	return (m);
}
