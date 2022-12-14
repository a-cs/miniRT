/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:32:22 by acarneir          #+#    #+#             */
/*   Updated: 2022/09/21 23:17:49 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	iter_world(t_rtx *rtx, t_hit_record *rec, t_ray ray)
{
	t_hit_record	temp_rec;
	int				hit_anything;
	double			t[2];
	t_sphere		*sp;
	t_list			*world;

	world = rtx->world;
	hit_anything = FALSE;
	t[T_MIN] = 0.0;
	t[T_MAX] = INFINITY;
	while (world)
	{
		sp = world->content;
		if (hit_sphere(sp, ray, t, &temp_rec))
		{
			printf("T\n");
			hit_anything = TRUE;
			t[T_MAX] = temp_rec.t;
			rec->front_face = temp_rec.front_face;
			rec->norm = temp_rec.norm;
			rec->point = temp_rec.point;
			rec->eye = vector_mul_scal(ray.direction, -1.0);
			rec->t = temp_rec.t;
		}
		world = world->next;
	}
	rec->color = lighting(sp->material, rtx, rec->point, rec->norm, rec->eye);
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

t_color	ray_color(t_rtx *rtx, t_ray ray)
{
	t_hit_record	rec;

	if (iter_world(rtx, &rec, ray))
		return (rec.color);
	return (vector_to_color(create_vector(0, 0, 0, 0)));
}

t_vec	ray_at(t_ray ray, double t)
{
	t_vec	point;

	point = vector_add(ray.origin, vector_mul_scal(ray.direction, t));
	return (point);
}

t_ray	create_ray(t_vec origin, t_vec direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
