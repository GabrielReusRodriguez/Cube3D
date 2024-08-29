/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:20:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/29 22:27:26 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "error.h"
#include "mlx.h"


//https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
int	engine_render(void *param)
{
	t_engine	*engine;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	void	*image;
	
	engine = (t_engine *)param;
	image = mlx_new_image(engine->mlx, SCREEN_DEFAULT_WIDTH, SCREEN_DEFAULT_HEIGH);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	(void)buffer;
	mlx_put_image_to_window(engine->mlx, engine->mlx_win, image, 0, 0);
	mlx_destroy_image(engine->mlx, image);
	free (image);
	return (0);
}