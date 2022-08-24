/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:25:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/24 02:56:49 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	hit_sphere(t_vec3 center, double radius, t_ray ray)
{
	t_vec3	orig_to_center;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	orig_to_center = vector_sub(ray.origin, center);
	a = vector_dot(ray.direction, ray.direction);
	b = 2.0 * vector_dot(orig_to_center, ray.direction);
	c = vector_dot(orig_to_center, orig_to_center) - (radius * radius);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0.0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}
