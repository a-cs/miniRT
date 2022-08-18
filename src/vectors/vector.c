/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:54:53 by acarneir          #+#    #+#             */
/*   Updated: 2022/08/17 23:01:06 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vector_length(t_vec3 a)
{
	double	length;

	length = a.x * a.x + a.y * a.y + a.z * a.z;
	length = sqrt(length);
	return (length);
}

t_vec3	vector_div(t_vec3 a, double b)
{
	t_vec3	vec;

	vec.x = a.x / b;
	vec.y = a.y / b;
	vec.z = a.z / b;
	return (vec);
}

t_vec3	vector_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

t_vec3	vector_add(t_vec3 a, t_vec3 b)
{
	t_vec3	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}

t_vec3	create_vector(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
