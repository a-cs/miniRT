/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiplications.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:19:43 by acarneir          #+#    #+#             */
/*   Updated: 2022/08/27 03:52:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vector_dot(t_vec a, t_vec b)
{
	double	dot;

	dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (dot);
}

t_vec	vector_cross(t_vec a, t_vec b)
{
	t_vec	vec;

	vec.x = a.y * b.z - a.z * b.y;
	vec.y = a.z * b.x - a.x * b.z;
	vec.z = a.x * b.y - a.y * b.x;
	vec.w = 0;
	return (vec);
}

t_vec	vector_mul(t_vec a, t_vec b)
{
	t_vec	vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	vec.z = a.z * b.z;
	vec.w = a.w * b.w;
	return (vec);
}

t_vec	vector_mul_scal(t_vec a, double b)
{
	t_vec	vec;

	vec.x = b * a.x;
	vec.y = b * a.y;
	vec.z = b * a.z;
	vec.w = b * a.w;
	return (vec);
}

t_vec	unit_vector(t_vec a)
{
	t_vec	vec;
	double	len;

	len = vector_length(a);
	vec.x = a.x / len;
	vec.y = a.y / len;
	vec.z = a.z / len;
	vec.w = a.w / len;
	return (vec);
}
