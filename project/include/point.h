/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:54:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/20 22:01:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_H
# define POINT_H

# include <stddef.h>

typedef	struct s_point
{
	int		x;
	int		y;
}	t_point;

double	point_calculate_distance(t_point point1, t_point point2);

#endif