/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/22 22:17:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

void	map_destroy(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->tiles != NULL)
	{
		while (i < map->height)
		{
			if (map->tiles[i] != NULL)
				free (map->tiles[i]);
			i++;
		}
		free (map->tiles);
		map->tiles = NULL;
		map->height = 0;
		map->width = 0;
	}
}