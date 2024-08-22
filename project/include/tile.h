/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:32:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/22 21:18:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	TILE_H
# define TILE_H

# include "types.h"
typedef enum e_tile_type
{
	EMPTY,
	WALL
}	t_tile_type;

typedef struct s_tile
{
	size_t		x;
	size_t		y;
	t_tile_type	type;

}	t_tile;

#endif