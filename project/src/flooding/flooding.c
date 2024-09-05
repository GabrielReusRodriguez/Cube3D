/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/05 20:19:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"
#include "tile.h"


static bool	flood_map_init_buffer(t_config cfg, t_list **tiles_buffer)
{
	t_tile	*tile;
	t_list	*node;

	tile = (t_tile *)malloc(sizeof(tile));
	if (tile == NULL)
		return(error_perror_critical(), false);
	*tile = tile_new(cfg.player_position.x, cfg.player_position.y, \
				cfg.map.map[cfg.player_position.x][cfg.player_position.y]);
	node = ft_lstnew(tile);
	if (node == NULL)
	{
		free (tile);
		return(error_perror_critical(), false);
	}
	ft_lstadd_back(tiles_buffer, node);
	return (true);
}

static	bool	flood_map_next_iteration(t_config cfg, t_list **tiles_buffer, \
					bool *is_open)
{
	t_list	*node;
	t_tile	*tile;
	
	*is_open = false;
	node = *tiles_buffer;
	tile = (t_tile *)node->content;
	if (tile->type == TILE_UNKNOWN || \
			tile->y == 0 || tile->y >= cfg.map.height || \
			tile->x == 0 || tile->y >= cfg.map.width)
	{
		*is_open = true;
		return (true);
	}
	if (tile->type != TILE_EMPTY || tile->type != TILE_PLAYER)
	{
			//añade tiles hay que comprobar que  
	}
	ft_lstdelone(*tiles_buffer, free);
	return (true);
}

bool	flood_map(t_config cfg, bool *is_closed)
{
	t_list	*tiles_buffer;
	bool	is_open;

	tiles_buffer = NULL;
	if (!flood_map_init_buffer(cfg, &tiles_buffer))
		return (false);
	while(ft_lstsize(tiles_buffer) > 0)
	{
		if (!flood_map_next_iteration(cfg, &tiles_buffer, &is_open))
			return (ft_lstclear(&tiles_buffer, free), false);
		if (is_open)
		{
			*is_closed = false;
			ft_lstclear(&tiles_buffer, free);
			error_print_critical("The map is NOT closed where the player is.");
			return (true);
		}
	}
	ft_lstclear(&tiles_buffer, free);
	*is_closed = true;
	return (true);
}