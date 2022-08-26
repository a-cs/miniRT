/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:32:22 by acarneir          #+#    #+#             */
/*   Updated: 2022/08/25 22:02:29 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	iter_world(t_list *world, t_hit_record *rec, t_ray ray)
{
	t_hit_record	temp_rec;
	int				hit_anything;
	double			t[2];
	t_sphere		*sp;

	hit_anything = FALSE;
	t[T_MIN] = 0.0;
	t[T_MAX] = INFINITY;
	while (world)
	{
		sp = world->content;
		if (hit_sphere(sp, ray, t, &temp_rec))
		{
			hit_anything = TRUE;
			t[T_MAX] = temp_rec.t;
			rec->front_face = temp_rec.front_face;
			rec->norm = temp_rec.norm;
			rec->point = temp_rec.point;
			rec->t = temp_rec.t;
		}
		world = world->next;
	}
	return (hit_anything);
}

void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	if (vector_dot(ray.direction, rec->norm) < 0.0)
		rec->front_face = TRUE;
	else
	{
		rec->front_face = FALSE;
		rec->norm = vector_mul_scal(rec->norm, -1.0);
	}
}

t_vec3	ray_color(t_rtx *rtx, t_ray ray)
{
	t_vec3			color;
	t_vec3			unit_direction;
	t_hit_record	rec;
	double			t;

	if (iter_world(rtx->world, &rec, ray))
	{
		return (vector_mul_scal(create_vector(rec.norm.x + 1.0,
					rec.norm.y + 1.0, rec.norm.z + 1.0), 0.5));
	}
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
