/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:58:02 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 20:58:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_new(unsigned char _r, unsigned char _g, unsigned char _b)
{
	t_color color;

	color.r = _r;
	color.g = _g;
	color.b = _b;
	return (color);
}