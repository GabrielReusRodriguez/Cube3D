/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:20:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/31 19:42:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "error.h"
#include "mlx.h"
#include "frame.h"


static void	engine_render_background(t_engine *engine, t_frame *frame)
{
	size_t	i;
	size_t	j;
	t_color	color;
	t_point	pixel;

	i = 0;
	while (i < SCREEN_DEFAULT_WIDTH)
	{
		j = 0;
		while(j < SCREEN_DEFAULT_HEIGH)
		{
			pixel = point_new(i,j);
			if (j < engine->screen.middle_y)
				color =  engine->cfg->ceiling_color;
			else
				color = engine->cfg->floor_color;
			frame_set_pixel(frame, color, pixel);
			j++;
		}
		i++;
	}
}

static bool	engine_render_create_frame(t_engine *engine, t_frame *frame)
{
	engine_render_background(engine, frame);
	mlx_put_image_to_window(engine->mlx, engine->mlx_win, frame->image, 0, 0);
	//engine->mlx_image = frame->image;
	return (true);
}

//https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
int	engine_render(void *param)
{
	t_engine	*engine;
	t_frame		frame;

	engine = (t_engine *)param;
	if (!frame_init(engine, &frame))
	{
		frame_destroy(engine, &frame);
		engine_destroy(engine);
		exit(EXIT_FAILURE);
	}
	if (!engine_render_create_frame(engine, &frame))
	{
		frame_destroy(engine, &frame);
		engine_destroy(engine);
		exit(EXIT_FAILURE);
	}
	frame_destroy(engine, &frame);
	return (0);
}	
	
/*
	image = mlx_new_image(engine->mlx, SCREEN_DEFAULT_WIDTH, SCREEN_DEFAULT_HEIGH);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	(void)buffer;
	mlx_put_image_to_window(engine->mlx, engine->mlx_win, image, 0, 0);
	mlx_destroy_image(engine->mlx, image);
	free (image);
*/
