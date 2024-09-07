/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:33:19 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 21:24:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "events.h"
//#include "mlx.h"
#include "MLX42.h"
#include "libft.h"
#include "error.h"

//#include <X11/X.h>

bool	engine_init(t_engine *engine, t_config *cfg)
{
	engine->mlx = NULL;
	engine->mlx_win = NULL;
	engine->cfg = cfg;
	engine->textures[TEXTURE_NORTH].mlx_image = NULL;
	engine->textures[TEXTURE_SOUTH].mlx_image = NULL;
	engine->textures[TEXTURE_WEST].mlx_image = NULL;
	engine->textures[TEXTURE_EAST].mlx_image = NULL;
	engine->map.map = NULL;
	engine->screen.title = NULL;
	//camera_init();
	return (true);
}

bool	engine_start(t_engine *engine)
{
	if (!screen_init(&(engine->screen)))
		return (false);
	engine->mlx = mlx_init();
	if (engine->mlx == NULL)
		return (error_print_critical("Cannot initialize mlx."), false);
	if(!engine_textures_load(engine))
		return (false);
	engine->mlx_win = mlx_new_window(engine->mlx, engine->screen.x, engine->screen.y, engine->screen.title);
//	engine->mlx_win = mlx_new_window(engine->mlx, engine->screen.x, engine->screen.y, SCREEN_DEFAULT_TITLE);
	if (engine->mlx_win == NULL)
		return (error_print_critical("cannot initialize mlx window"), false);
	mlx_key_hook(engine->mlx_win, on_keydown, engine);
	mlx_loop_hook(engine->mlx, engine_render, engine);
	mlx_hook(engine->mlx_win, ON_DESTROY, NoEventMask, on_destroy, engine);
	return (true);
}

void	engine_destroy(t_engine *engine)
{
	map_destroy(&engine->map);
	if (engine->mlx != NULL)
	{
		engine_textures_destroy(engine);
		if (engine->mlx_win != NULL)
		{
			mlx_clear_window(engine->mlx, engine->mlx_win);
			mlx_destroy_window(engine->mlx, engine->mlx_win);
		}
		mlx_destroy_display(engine->mlx);
		free(engine->mlx);
	}
	screen_destroy(&engine->screen);
	config_destroy(engine->cfg);
}

void	engine_loop(t_engine *engine)
{
	mlx_loop(engine->mlx);
}

