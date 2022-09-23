/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 04:05:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/22 23:22:11 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	populate_list(t_rtx *rtx)
{
	t_sphere	*sp;
	double		center[3];

	center[0] = 0;
	center[1] = 0;
	center[2] = 0;
	sp = crete_sphere(center, 10);
	rtx->world = NULL;
	ft_lstadd_back(&rtx->world, ft_lstnew((void *)sp));
}

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

double	**view_transform(t_vec from, t_vec to, t_vec up)
{
	t_vec	forward;
	t_vec	upn;
	t_vec	left;
	t_vec	true_up;
	double	**orientation;
	double	**translation;
	double	**result;

	forward = unit_vector(vector_sub(to, from));
	upn = unit_vector(up);
	if (to.x == 0 || up.x == 0 || from.x == 0)
	{
		
	}
	left = vector_cross(forward, upn);
	true_up = vector_cross(left, forward);
	orientation = identity_matrix(4);
	orientation[0][0] = left.x;
	orientation[0][1] = left.y;
	orientation[0][2] = left.z;
	orientation[1][0] = true_up.x;
	orientation[1][1] = true_up.y;
	orientation[1][2] = true_up.z;
	orientation[2][0] = -1.0 * forward.x;
	orientation[2][1] = -1.0 * forward.y;
	orientation[2][2] = -1.0 * forward.z;
	translation = m_translation(-1.0 * from.x, -1.0 * from.y, -1.0 * from.z);
	// translation = identity_matrix(4);
	result = m_multiply(orientation, translation, 4);
	ft_free_double_matrix(orientation, 4);
	ft_free_double_matrix(translation, 4);
	return (result);
}

void	initiate_rtx(t_rtx *rtx)
{
	double	fov;
	double	theta;
	t_vec	from;
	t_vec	to;
	t_vec	up;

	fov = 90;
	theta = degree_to_radian(fov);
	// rtx->viewport_height = 2 * tan(theta / 2);
	// rtx->viewport_width = (16.0 / 9.0) * rtx->viewport_height;
	rtx->viewport_width = 2 * tan(theta / 2);
	rtx->viewport_height = rtx->viewport_width / 2;
	rtx->pixel_size = rtx->viewport_width / rtx->viewport_height; 
	rtx->focal_length = 1.0;
	from = create_vector(-10, 0, 30, 1);
	to = create_vector(0, 0, 0, 1);
	up = create_vector(0, -0.809017, 0.587785, 0);
	rtx->cam_transform = view_transform(from, to, up);
	populate_list(rtx);
	rtx->point_light.position = create_vector(-10, 10, 10, 1);
	rtx->point_light.intensity = vector_to_color(create_vector(1, 1, 1, 1));
	// printf("llc.x = %f, llc.y = %f, llc.z = %f\n", rtx->lower_left_corner.x, rtx->lower_left_corner.y, rtx->lower_left_corner.z);
}
