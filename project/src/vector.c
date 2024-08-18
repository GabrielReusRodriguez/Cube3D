/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:06:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/16 23:12:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

t_vector	vector_init_points(t_point a, t_point b)
{
	t_vector	vector;

	vector.x = b.x - a.x;
	vector.y = b.y - a.y;
	vector_calculate_modulus(&vector);
	vector_normalize(&vector);
	return (vector);
}

t_vector	vector_init_values(double _x, double _y)
{
	t_vector	vector;

	vector.x = _x;
	vector.y = _y;
	vector_calculate_modulus(&vector);
	vector_normalize(&vector);
	return (vector);
}

void		vector_calculate_modulus(t_vector *vector)
{
	double	x_square;
	double	y_square;
	
	x_square = pow(vector->x, 2.0f);
	y_square = pow(vector->y, 2.0f);
	vector->modulus = sqrt(x_square + y_square);
}

void	vector_normalize(t_vector	*vector)
{
	vector->x = vector->x /  vector->modulus;
	vector->y = vector->y / vector->modulus;
	vector->modulus = 1.0f;
}

void	vector_rotate(t_vector *vector, float angle)
{
	double	px;
	double	py;

	px = vector->x * cos(angle) - vector->y * sin(angle);
	py = vector->x * sin(angle) + vector->y * cos(angle);	
	vector->x = px;
	vector->y = py;
	vector_calculate_modulus(vector);
	vector_normalize(vector);
}