/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiplications.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:19:43 by acarneir          #+#    #+#             */
/*   Updated: 2022/08/17 22:57:44 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vector_dot(t_vec3 a, t_vec3 b)
{
	double	dot;

	dot = a.x * b.x + a.y * b.y + a.z * b.z;
	return (dot);
}

t_vec3	vector_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.y * b.z - a.z * b.y;
	vec.y = a.z * b.x - a.x * b.z;
	vec.z = a.x * b.y - a.y * b.x;
	return (vec);
}

t_vec3	vector_mul(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	vec.z = a.z * b.z;
	return (vec);
}

t_vec3	vector_mul_scal(t_vec3 a, double b)
{
	t_vec3	vec;

	vec.x = b * a.x;
	vec.y = b * a.y;
	vec.z = b * a.z;
	return (vec);
}

t_vec3	unit_vector(t_vec3 a)
{
	t_vec3	vec;
	double	len;

	len = vector_length(a);
	vec.x = a.x / len;
	vec.y = a.y / len;
	vec.z = a.z / len;
	return (vec);
}
