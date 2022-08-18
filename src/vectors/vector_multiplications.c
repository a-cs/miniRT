/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiplications.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:19:43 by acarneir          #+#    #+#             */
/*   Updated: 2022/08/17 22:19:58 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec3	vector_mul(t_vec3 a, double b)
{
	t_vec3	vec;

	vec.x = b * a.x;
	vec.y = b * a.y;
	vec.z = b * a.z;
	return (vec);
}
