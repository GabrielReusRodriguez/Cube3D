/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:18:33 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/18 21:19:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "engine.h"

bool	engine_update_screen_size(t_engine *engine)
{
	int	x;
	int	y;

	mlx_get_screen_size(engine->mlx, &x, &y);
	screen_update_size(&engine->screen, x, y);
	return (true);
}