/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:03:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/09/08 23:07:49 by acarneir         ###   ########.fr       */
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
# define FALSE 0
# define TRUE 1
# define T_MIN 0
# define T_MAX 1
# define ESC 0xff1b

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

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec;

typedef struct s_hit_record
{
	t_vec	point;
	t_vec	norm;
	double	t;
	int		front_face;
}	t_hit_record;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_rtx
{
	t_mlx	mlx;
	t_maps	maps;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_vec	origin;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	lower_left_corner;
	t_list	*world;
}	t_rtx;

typedef struct s_sphere
{
	t_vec	center;
	double	radius;
}	t_sphere;

t_vec	create_vector(double x, double y, double z, double w);
t_vec	vector_add(t_vec a, t_vec b);
t_vec	vector_sub(t_vec a, t_vec b);
t_vec	vector_mul(t_vec a, t_vec b);
t_vec	vector_mul_scal(t_vec a, double b);
t_vec	vector_div(t_vec a, double b);
t_vec	vector_cross(t_vec a, t_vec b);
double	vector_length(t_vec a);
double	vector_dot(t_vec a, t_vec b);
t_vec	unit_vector(t_vec a);
void	color_unnormalizer(t_color *norm_rgb, t_color *rgb);
void	color_normalizer(int *rgb, double *norm_rgb);
int		encode_rgb(t_color color);
void	calculate(t_rtx *rtx);
t_ray	create_ray(t_vec origin, t_vec direction);
t_vec	ray_at(t_ray ray, double t);
t_color	ray_color(t_rtx *rtx, t_ray ray);
int		hit_sphere(t_sphere *sp, t_ray ray, double *t, t_hit_record *rec);
void	set_face_normal(t_ray ray, t_hit_record *rec);
int		render(t_rtx *rtx);
void	initiate_rtx(t_rtx *rtx);
t_color	vector_to_color(t_vec vec);
double	**m_multiply(double **a, double **b, int size);
double	**create_matrix(int size);
double	**identity_matrix(int size);
double	**m_transpose(double **a, int size);
double	m_det(double **m, int size);
double	cofactor(double **m, int size, int row, int col);
double	**m_inverse(double **m, int size);
t_vec	multiply_m_v(double **m, t_vec v);
double	**m_translation(double x, double y, double z);
double	**m_scaling(double x, double y, double z);
double	**m_rotate_x(double n_angle);
double	**m_rotate_y(double n_angle);
double	**m_rotate_z(double n_angle);

#endif
