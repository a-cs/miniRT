/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:48:11 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/21 23:13:14 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_sphere	*crete_sphere(double center[3], double radius)
{
	t_sphere	*sp;
	double		**translation;
	double		**scaling;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	sp->center = create_vector(0, 0, 0, 1);
	sp->radius = 1;
	translation = m_translation(center[0], center[1], center[2]);
	scaling = m_scaling(radius, radius, radius);
	sp->transform = m_multiply(translation, scaling, 4);
	free(translation);
	free(scaling);
	sp->material.color = vector_to_color(create_vector(0.1, 1, 0.5, 0));
	sp->material.ambient = 0.2;
	sp->material.diffuse = 0.7;
	sp->material.specular = 0.3;
	sp->material.shininess = 50;
	return (sp);
}
