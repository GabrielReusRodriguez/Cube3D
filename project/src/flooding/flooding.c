/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 20:25:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"
#include "tile.h"


static bool	flood_update_lists(t_flooding *flood, t_tile *tile)
{
	t_tile	*copy_tile;
	t_list	*node;

	if (!tile_copy_ptr(tile, &copy_tile))
		return (false);
	node = ft_lstnew(copy_tile);
	if (node == NULL)
		return (error_print_critical("Cannot create new node."), false);
	ft_lstdel_front(&flood->to_visit);
	ft_lstadd_back(&flood->visited, node);	
	return (true);
}

static	bool	flood_get_neighbour(t_config cfg, t_list **node, int _x, int _y)
{
	int		x;
	int		y;
	t_tile	*tile;

	*node = NULL;
	x = _x;
	y = _y;
	if (x >= 0 && (size_t)x < cfg.map.width)
	{
		if (y >= 0 && (size_t)y < cfg.map.height)
		{
			tile = (t_tile *)malloc(sizeof(t_tile));
			if (tile == NULL)
				return (error_perror_critical(), false);
			*tile = tile_new(x, y, cfg.map.map[x][y]);
			*node = ft_lstnew(tile);
			if (*node == NULL)
				return (error_print_critical("Cannot create node."), false);
		}
	}
	return (true);
}

static bool	flood_add_neighbours(t_config cfg, t_flooding *flood, t_tile tile)
{
	t_list	*node;

	if (!flood_get_neighbour(cfg, &node, tile.x + 1, tile.y))
		return (false);
	ft_lstadd_back(&flood->to_visit, node);
	if (!flood_get_neighbour(cfg, &node, tile.x, tile.y + 1))
		return (false);
	ft_lstadd_back(&flood->to_visit, node);
	if (!flood_get_neighbour(cfg, &node, tile.x - 1, tile.y))
		return (false);
	ft_lstadd_back(&flood->to_visit, node);
	if (!flood_get_neighbour(cfg, &node, tile.x, tile.y - 1))
		return (false);
	ft_lstadd_back(&flood->to_visit, node);
	return (true);	
}

static	bool	flood_map_next_iteration(t_config cfg, t_flooding *flood)
{
	t_list	*node;
	t_tile	*tile;
	
	flood->is_open = false;
	node = flood->to_visit;
	tile = (t_tile *)node->content;
	if (tile->type == TILE_UNKNOWN || tile->type == TILE_VOID || \
			tile->y == 0 || tile->y >= cfg.map.height || \
			tile->x == 0 || tile->y >= cfg.map.width)
	{
		flood->is_open = true;
		return (true);
	}
	if(!flood_add_neighbours(cfg, flood, *tile))
		return (false);
	if (!flood_update_lists(flood, tile))
		return (false);
	return (true);
}

bool	flood_map(t_config cfg, bool *is_open)
{
	t_flooding	flood;

	if (!flood_init(cfg, &flood))
		return (false);
	while(ft_lstsize(flood.to_visit) > 0)
	{
		if (!flood_map_next_iteration(cfg, &flood))
			return (flood_destroy(&flood), false);
		if (flood.is_open)
		{
			*is_open = true;
			flood_destroy(&flood);
			error_print_critical("The map is NOT closed where the player is.");
			return (true);
		}
	}
	flood_destroy(&flood);
	*is_open = false;
	return (true);
}