/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:28:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 19:54:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "tile.h"
# include "types.h"

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_tile	**tiles;

}	t_map;

//map.c
t_tile_type map_determine_tile_type(char tile);
void	map_destroy(t_map *map);

//map_loader.c
bool	map_load(t_map *map, const char *filename);

//map_parser.c
bool	map_parse(t_map *map, const char *filename);

#endif