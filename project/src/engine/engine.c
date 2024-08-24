/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:33:19 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 20:39:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "engine.h"
#include "events.h"
#include "mlx.h"

#include <X11/X.h>

bool	engine_init(t_engine *engine, t_map *map)
{
	engine->mlx = NULL;
	engine->mlx_win = NULL;
	engine->mlx = mlx_init();
	if (engine->mlx == NULL)
		return (false);
	engine->map = map;
	//camera_init();
	return (true);
}

bool	engine_start(t_engine *engine)
{
	if (engine->mlx == NULL)
	{
		return (false);
	}
	if (!screen_init(&(engine->screen)))
	{
		return (false);
	}
	engine->mlx_win = mlx_new_window(engine->mlx, engine->screen.x, engine->screen.y, engine->screen.title);
	if (engine->mlx_win == NULL)
	{
		return (false);
	}
	mlx_key_hook(engine->mlx_win, on_keydown, engine);
	mlx_loop_hook(engine->mlx, engine_render, engine);
	mlx_hook(engine->mlx_win, ON_DESTROY, NoEventMask, on_destroy, engine);
	return (true);
}

//	mlx_destroy_display(engine->mlx); => da segmentation fault si lo llamo.
void	engine_destroy(t_engine *engine)
{
	map_destroy(engine->map);
	engine_clear_window(engine);
	mlx_destroy_window(engine->mlx, engine->mlx_win);
	screen_destroy(&engine->screen);
}

bool	engine_clear_window(t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->mlx_win);
	return (true);
}

void	engine_loop(t_engine *engine)
{
	mlx_loop(engine->mlx);
}

