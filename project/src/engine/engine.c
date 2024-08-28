/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:33:19 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/28 21:19:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "events.h"
#include "mlx.h"
#include "libft.h"
#include "error.h"

#include <X11/X.h>

bool	engine_init(t_engine *engine, t_config *cfg)
{
	engine->mlx = NULL;
	engine->mlx_win = NULL;
	engine->mlx_image = NULL;
	engine->cfg = cfg;
	engine->textures[TEXTURE_NORTH].mlx_image = NULL;
	engine->textures[TEXTURE_SOUTH].mlx_image = NULL;
	engine->textures[TEXTURE_WEST].mlx_image = NULL;
	engine->textures[TEXTURE_EAST].mlx_image = NULL;
	engine->map.tiles = NULL;
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
	engine->mlx_image = mlx_new_image(engine->mlx, engine->screen.x, engine->screen.y);
	if (engine->mlx_image == NULL)
		return (error_print_critical("Cannot create mlx image."), false);
	mlx_key_hook(engine->mlx_win, on_keydown, engine);
	mlx_loop_hook(engine->mlx, engine_render, engine);
	mlx_hook(engine->mlx_win, ON_DESTROY, NoEventMask, on_destroy, engine);
	return (true);
}

//	mlx_destroy_display(engine->mlx); => da segmentation fault si lo llamo.
void	engine_destroy(t_engine *engine)
{
	map_destroy(&engine->map);
	if (engine->mlx != NULL)
	{
		if (engine->mlx_win != NULL)
		{
			engine_clear_window(engine);
			mlx_destroy_window(engine->mlx, engine->mlx_win);
		}
		else
			free (engine->mlx);
	}
	if (engine->mlx_image != NULL)
		free (engine->mlx_image);
	screen_destroy(&engine->screen);
	engine->textures[TEXTURE_NORTH].mlx_image = \
			ft_ptr_free(engine->textures[TEXTURE_NORTH].mlx_image);
	engine->textures[TEXTURE_SOUTH].mlx_image = \
			ft_ptr_free(engine->textures[TEXTURE_SOUTH].mlx_image);
	engine->textures[TEXTURE_WEST].mlx_image = \
			ft_ptr_free(engine->textures[TEXTURE_WEST].mlx_image);
	engine->textures[TEXTURE_EAST].mlx_image = \
			ft_ptr_free(engine->textures[TEXTURE_EAST].mlx_image);
	config_destroy(engine->cfg);
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

