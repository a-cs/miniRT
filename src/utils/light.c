/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:36:09 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/15 05:02:53 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"


// static t_vec	ambient(t_material m, t_rtx *rtx)
// {
// 	t_vec	effective_color;

// 	effective_color = vector_mul(color_to_vector(m.color),
// 			color_to_vector(rtx->point_light.intensity));
// 	// printf("effective_color: [%f][%f][%f][%f]\n", effective_color.x, effective_color.y, effective_color.z, effective_color.w);
// 	return (vector_mul_scal(effective_color, m.ambient));
// }

static t_vec	diffuse(t_material m, t_rtx *rtx, double light_dot_normal)
{
	t_vec	effective_color;

	effective_color = vector_mul(color_to_vector(m.color),
			color_to_vector(rtx->point_light.intensity));
	return (vector_mul_scal(effective_color, (m.diffuse * light_dot_normal)));
}

t_vec	reflect(t_vec in, t_vec norm)
{
	return (vector_sub(in,
			vector_mul_scal(norm, (vector_dot(in, norm) * 2.0))));
}

t_color	lighting(t_material m, t_rtx *rtx, t_vec point, t_vec norm)
{
	t_vec	ambientv;
	t_vec	diffusev;
	t_vec	specularv;
	t_vec	lightv;
	double	light_dot_normal;

	// ambientv = ambient(m, rtx);
	// printf("ambient: [%f][%f][%f][%f]\n", ambientv.x, ambientv.y, ambientv.z, ambientv.w);
	ambientv = create_vector(0, 0, 0, 0);
	lightv = unit_vector(vector_sub(rtx->point_light.position, point));
	light_dot_normal = vector_dot(lightv, norm);
	// printf("light_dot_normal: %f\n", light_dot_normal);
	if (light_dot_normal < 0)
	{
		diffusev = create_vector(0, 0, 0, 0);
		specularv = create_vector(0, 0, 0, 0);
	}
	else
	{
		diffusev = diffuse(m, rtx, light_dot_normal);
		specularv = create_vector(0, 0, 0, 0);
	}
	return (vector_to_color(
			vector_add(vector_add(ambientv, diffusev), specularv)));
	// return (vector_to_color(ambientv));
}
