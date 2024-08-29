/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:58:02 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/29 23:19:51 by gabriel          ###   ########.fr       */
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

char	color_2_pixel(t_color color, t_mlx_image img, t_engine *engine)
{
	int color = 0xABCDEF;

	if (pixel_bits != 32)
    	color = mlx_get_color_value(mlx, color);

	for(int y = 0; y < 360; ++y)
		for(int x = 0; x < 640; ++x)
		{
    		int pixel = (y * line_bytes) + (x * 4);

			if (endian == 1)        // Most significant (Alpha) byte first
    		{
        		buffer[pixel + 0] = (color >> 24);
        		buffer[pixel + 1] = (color >> 16) & 0xFF;
        		buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
    		}
			else if (endian == 0)   // Least significant (Blue) byte first
    		{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
	}
}