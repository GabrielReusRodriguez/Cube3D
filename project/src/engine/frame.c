/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:49:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/30 22:39:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "frame.h"
#include "error.h"
#include "mlx.h"

bool	frame_init(t_engine *engine, t_frame *frame)
{
	frame->image = mlx_new_image(engine->mlx, SCREEN_DEFAULT_WIDTH, SCREEN_DEFAULT_HEIGH);
	if (frame->image == NULL)
		return (error_print_critical("Cannot get mlx image."), false);
	frame->buffer = mlx_get_data_addr(frame->image, &frame->pixel_bits, &frame->line_bytes, &frame->endian);
	return (true);
}

void	frame_destroy(t_engine *engine, t_frame *frame)
{
	if (frame->buffer != NULL)
		free(frame->buffer);
	if (frame->image != NULL)
		mlx_destroy_image(engine->mlx, frame->image);
}

void	frame_set_pixel(t_frame *frame, t_color color, t_point pixel)
{
	/*
	
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
	*/

	int pixel_pos;

	pixel_pos =  (pixel.y * frame->line_bytes) + (pixel.x * 4);
	if (frame->endian == 1)
	{
		frame->buffer[pixel_pos + 0] = color.a;
		frame->buffer[pixel_pos + 1] = color.b;
		frame->buffer[pixel_pos + 2] = color.g;
		frame->buffer[pixel_pos + 3] = color.r;
	}
	else
	{
		frame->buffer[pixel_pos + 0] = color.r;
		frame->buffer[pixel_pos + 1] = color.g;
		frame->buffer[pixel_pos + 2] = color.b;
		frame->buffer[pixel_pos + 3] = color.a;
	}
}

void	frame_set_pixel_int(t_engine *engine, t_frame *frame, int color, t_point pixel)
{
	int pixel_pos;

	if (frame->pixel_bits != 32)
		color = mlx_get_color_value(engine->mlx, color);
	pixel_pos =  (pixel.y * frame->line_bytes) + (pixel.x * 4);
	if (frame->endian == 1)        // Most significant (Alpha) byte first
	{
		frame->buffer[pixel_pos + 0] = (color >> 24);
		frame->buffer[pixel_pos + 1] = (color >> 16) & 0xFF;
		frame->buffer[pixel_pos + 2] = (color >> 8) & 0xFF;
		frame->buffer[pixel_pos + 3] = (color) & 0xFF;
	}
//	else if (frame->endian == 0)   // Least significant (Blue) byte first
	else
	{
		frame->buffer[pixel_pos + 0] = (color) & 0xFF;
		frame->buffer[pixel_pos + 1] = (color >> 8) & 0xFF;
		frame->buffer[pixel_pos + 2] = (color >> 16) & 0xFF;
		frame->buffer[pixel_pos + 3] = (color >> 24);
	}
}
