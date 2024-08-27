/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:49:35 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/27 22:18:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

bool	config_map_find_player(t_config *cfg)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cfg->map[i] != NULL)
	{
		j = 0;
		while (cfg->map[i][j] != '\0')
		{
			if (cfg->map[i][j] == 'N' || cfg->map[i][j] == 'S' || \
					cfg->map[i][j] == 'W' || cfg->map[i][j] == 'E' )
			{
				cfg->player_position = point_new(i,j);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool config_validate_map(t_config *cfg)
{
	(void)cfg;
	return (true);
}