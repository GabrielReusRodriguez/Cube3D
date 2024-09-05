/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:48:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/05 20:05:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "map.h"

t_tile	tile_new(size_t _x, size_t _y, char _type)
{
	t_tile	tile;

	tile.x = _x;
	tile.y = _y;
	tile.type = tile_determine_type(_type);
	return (tile);
}

t_tile_type tile_determine_type(char tile)
{
	if (tile == '0')
		return (TILE_EMPTY);
	if (tile == '1')
		return (TILE_WALL);
	if (tile == 'N' || tile == 'S' || tile == 'W' || tile == 'E')
		return (TILE_PLAYER);
	if (tile == ' ')
		return (TILE_VOID);
	return (TILE_UNKNOWN);
}
