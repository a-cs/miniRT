/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:03:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/23 00:06:41 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// INCLUDES
# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 450

# define ESC		0xff1b

typedef struct s_maps
{
	int	img_map[WINDOW_WIDTH][WINDOW_HEIGHT][3];
	int	pixel_map[WINDOW_WIDTH][WINDOW_HEIGHT];
}	t_maps;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
}	t_mlx;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_rtx
{
	t_mlx	mlx;
	t_maps	maps;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_vec3	origin;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	lower_left_corner;
}	t_rtx;

t_vec3	create_vector(double x, double y, double z);
t_vec3	vector_add(t_vec3 a, t_vec3 b);
t_vec3	vector_sub(t_vec3 a, t_vec3 b);
t_vec3	vector_mul(t_vec3 a, t_vec3 b);
t_vec3	vector_mul_scal(t_vec3 a, double b);
t_vec3	vector_div(t_vec3 a, double b);
t_vec3	vector_cross(t_vec3 a, t_vec3 b);
double	vector_length(t_vec3 a);
double	vector_dot(t_vec3 a, t_vec3 b);
t_vec3	unit_vector(t_vec3 a);
void	color_unnormalizer(t_vec3 *norm_rgb, t_vec3 *rgb);
void	color_normalizer(int *rgb, double *norm_rgb);
int		encode_rgb(t_vec3 color);
void	calculate(t_rtx *rtx);
t_ray	create_ray(t_vec3 origin, t_vec3 direction);
t_vec3	ray_at(t_ray ray, double t);
t_vec3	ray_color(t_ray ray);

#endif
