/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:03:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/19 22:59:44 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// INCLUDES
# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>

# define WINDOW_WIDTH 256
# define WINDOW_HEIGHT 256

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

typedef struct s_rtx
{
	t_mlx	mlx;
	t_maps	maps;
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
void	color_unnormalizer(double *norm_rgb, int *rgb);
void	color_normalizer(int *rgb, double *norm_rgb);
int		encode_rgb(int *rgb);
void	calculate(t_rtx *rtx);

#endif
