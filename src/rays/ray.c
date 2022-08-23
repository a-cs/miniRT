/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:32:22 by acarneir          #+#    #+#             */
/*   Updated: 2022/08/23 00:22:51 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec3	ray_color(t_ray ray)
{
	t_vec3	color;
	t_vec3	unit_direction;
	double	t;

	unit_direction = unit_vector(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	color = vector_add((vector_mul_scal(
					create_vector(1.0, 1.0, 1.0), (1.0 - t))),
			(vector_mul_scal(create_vector(0.5, 0.7, 1.0), t)));
	return (color);
}

t_vec3	ray_at(t_ray ray, double t)
{
	t_vec3	point;

	point = vector_add(ray.origin, vector_mul_scal(ray.direction, t));
	return (point);
}

t_ray	create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
