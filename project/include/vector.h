/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:58:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/16 22:46:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_H
# define VECTOR_H

# include "point.h"

typedef	struct s_vector
{
	double	x;
	double	y;
	double	modulus;
		
}	t_vector;


t_vector	vector_init_points(t_point a, t_point b);
t_vector	vector_init_values(double _x, double _y);
void		vector_calculate_modulus(t_vector *vector);
void		vector_normalize(t_vector	*vector);
void		vector_rotate(t_vector *vector, float angle);

#endif