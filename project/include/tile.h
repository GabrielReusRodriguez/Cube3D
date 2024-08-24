/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:32:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 21:00:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	TILE_H
# define TILE_H

# include "types.h"
typedef enum e_tile_type
{
	TILE_EMPTY,
	TILE_WALL,
	TILE_UNKNOWN
}	t_tile_type;

typedef struct s_tile
{
	size_t		x;
	size_t		y;
	t_tile_type	type;

}	t_tile;

t_tile	tile_new(size_t _x, size_t _y, t_tile_type _type);

#endif