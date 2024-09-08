/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:33:19 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/08 02:24:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "events.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include "error.h"

bool	engine_init(t_engine *engine, t_config *cfg)
{
	engine->mlx = NULL;
	engine->cfg = cfg;
	engine->textures[TEXTURE_NORTH].mlx_image = NULL;
	engine->textures[TEXTURE_SOUTH].mlx_image = NULL;
	engine->textures[TEXTURE_WEST].mlx_image = NULL;
	engine->textures[TEXTURE_EAST].mlx_image = NULL;
	engine->map.map = NULL;
	engine->screen.title = NULL;
	engine->img = NULL;
	//camera_init();
	return (true);
}

bool	engine_start(t_engine *engine)
{
	if (!screen_init(&(engine->screen)))
		return (false);
	engine->mlx = mlx_init(engine->screen.x, engine->screen.y, engine->screen.title, engine->screen.resize);
	if (engine->mlx == NULL)
		return (error_print_critical("Cannot initialize mlx."), false);
	if(!engine_textures_load(engine))
		return (false);
	engine->img = mlx_new_image(engine->mlx, engine->screen.x, engine->screen.y);
	if (engine->img == NULL)
		return(error_print_critical("Cannot create mlx image."), false);
	if (mlx_image_to_window(engine->mlx, engine->img, 0, 0) == -1)
		return(error_print_critical("Cannot deploy mlx img to window"), false);
	mlx_key_hook(engine->mlx, on_keydown, engine);
	mlx_loop_hook(engine->mlx, engine_render, engine);
	mlx_close_hook(engine->mlx, on_destroy, engine);
	return (true);
}

void	engine_destroy(t_engine *engine)
{
	map_destroy(&engine->map);
	if (engine->mlx != NULL)
	{
		engine_textures_destroy(engine);
		mlx_delete_image(engine->mlx, engine->img);
		mlx_terminate(engine->mlx);
	}
	screen_destroy(&engine->screen);
	config_destroy(engine->cfg);
}

void	engine_loop(t_engine *engine)
{
	mlx_loop(engine->mlx);
}

