/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:25:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/27 03:29:43 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	hit_sphere(t_sphere *sp, t_ray ray, double *t, t_hit_record *rec)
{
	t_vec	orig_to_center;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	root;

	orig_to_center = vector_sub(ray.origin, sp->center);
	a = vector_length(ray.direction) * vector_length(ray.direction);
	half_b = vector_dot(orig_to_center, ray.direction);
	c = (vector_length(orig_to_center) * vector_length(orig_to_center))
		- (sp->radius * sp->radius);
	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0.0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < t[T_MIN] || t[T_MAX] < root)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < t[T_MIN] || t[T_MAX] < root)
			return (FALSE);
	}
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->norm = vector_div(vector_sub(rec->point, sp->center), sp->radius);
	set_face_normal(ray, rec);
	return (TRUE);
}
