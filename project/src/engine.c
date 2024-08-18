/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:33:19 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/18 21:19:34 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

bool	engine_init(t_engine *engine)
{
	engine->mlx = NULL;
	engine->mlx_win = NULL;
	engine->mlx = mlx_init();
	if (engine->mlx == NULL)
		return (false);
	return (true);
}

bool	engine_new_window(t_engine *engine)
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
	return (true);
}

void	engine_destroy(t_engine *engine)
{
	engine_clear_window(engine);
	screen_destroy(&engine->screen);
	mlx_destroy_window(engine->mlx, engine->mlx_win);
}

bool	engine_clear_window(t_engine *engine)
{
	(void)engine;
	return (true);
}

void	engine_loop(t_engine *engine)
{
	mlx_loop(engine->mlx);
}


