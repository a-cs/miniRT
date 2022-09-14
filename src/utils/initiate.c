/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:05:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/14 02:15:05 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	populate_list(t_rtx *rtx)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	sp->center = create_vector(0.0, 0.0, -1.0, 1.0);
	sp->radius = 0.5;
	rtx->world = NULL;
	ft_lstadd_back(&rtx->world, ft_lstnew((void *)sp));
}

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

void	initiate_rtx(t_rtx *rtx)
{
	double	fov;
	double	theta;

	fov = 90;
	theta = degree_to_radian(fov);
	rtx->viewport_height = 2 * tan(theta / 2);
	rtx->viewport_width = (16.0 / 9.0) * rtx->viewport_height;
	rtx->focal_length = 1.0;
	rtx->origin = create_vector(0.0, 0.0, 0.0, 1.0);
	rtx->horizontal = create_vector(rtx->viewport_width, 0.0, 0.0, 0.0);
	rtx->vertical = create_vector(0.0, rtx->viewport_height, 0.0, 0.0);
	rtx->lower_left_corner = vector_sub(rtx->origin,
			vector_add(vector_div(rtx->horizontal, 2.0), vector_add(
					vector_div(rtx->vertical, 2.0),
					create_vector(0.0, 0.0, rtx->focal_length, 0.0))));
	populate_list(rtx);
	// printf("llc.x = %f, llc.y = %f, llc.z = %f\n", rtx->lower_left_corner.x, rtx->lower_left_corner.y, rtx->lower_left_corner.z);
}
