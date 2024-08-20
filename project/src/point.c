/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:41:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/20 21:45:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"


double	point_calculate_distance(t_point point1, t_point point2)
{
	double distance;
	double	x;
	double	y;

	x = point2.x - point1.x;
	y = point2.y - point1.y;
	distance = sqrt(x*x + y*y);
	return (distance);
}
