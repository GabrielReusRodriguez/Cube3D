/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:56:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/29 23:17:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "mlx_image.h"
# include "engine.h"
/*
typedef struct s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

} t_color;
*/

typedef struct s_color
{
	int r;
	int g;
	int b;

} t_color;


t_color	color_new(unsigned char _r, unsigned char _g, unsigned char _b);
char	color_2_pixel(t_color color, t_mlx_image img, t_engine *engine);


#endif