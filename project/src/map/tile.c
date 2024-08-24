/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:48:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 19:49:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"

t_tile	tile_init(size_t _x, size_t _y, t_tile_type _type)
{
	t_tile	tile;

	tile.x = _x;
	tile.y = _y;
	tile.type = _type;
	return (tile);
}