/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:56:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/30 21:35:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

//# include "engine.h"

typedef struct s_engine t_engine;

typedef struct s_color
{
	int r;
	int g;
	int b;
	int	a;

} t_color;


t_color	color_new(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
char	color_2_pixel(t_color color, t_engine *engine);

#endif