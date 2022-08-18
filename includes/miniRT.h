/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:03:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/08/17 22:25:09 by acarneir         ###   ########.fr       */
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


t_vec3	create_vector(double x, double y, double z);
t_vec3	vector_add(t_vec3 a, t_vec3 b);
t_vec3	vector_sub(t_vec3 a, t_vec3 b);
t_vec3	vector_mul(t_vec3 a, double b);
t_vec3	vector_div(t_vec3 a, double b);
double	vector_length(t_vec3 a);
#endif
