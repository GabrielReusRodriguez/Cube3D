/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:20:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/28 21:49:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "engine.h"
#include "error.h"

//https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
int	engine_render(void *param)
{
	t_engine	*engine;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	
	engine = (t_engine *)param;
	buffer = mlx_get_data_addr(engine->mlx_image, &pixel_bits, &line_bytes, &endian);

	mlx_put_image_to_window(engine->mlx, engine->mlx_win, engine->mlx_image, 0, 0);
//	printf("\tFIN RENDER");
	return (0);
}