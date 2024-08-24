/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:08:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 21:54:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "config_file.h"
#include "error.h"

static	void	config_file_init_vars(t_config_file *config)
{
	config->map = NULL;
	config->map_lines = NULL;
	config->north_texture = NULL;
	config->south_texture = NULL;
	config->east_texture = NULL;
	config->west_texture = NULL;
}

bool	config_file_init(t_config_file *cfg, const char *filename)
{
	int fd;

	config_file_init_vars(cfg);
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		return (error_perror_critical(), false);
	if (!config_file_load(cfg, fd))
		return (false);
	close (fd);
	return (true);
}

static void	config_file_destroy_map(t_config_file *cfg)
{
	char	**map;
	size_t	i;

	map = cfg->map;
	if (map != NULL)
	{
		i = 0;
		while (map[i] != NULL)
		{
			if (map[i] != NULL)
				free(map[i]);
			i++;
		}
		free(map);
		cfg->map = NULL;
	}
}
void	config_file_destroy(t_config_file *cfg)
{
	config_file_destroy_map(cfg);
	ft_lstclear(&cfg->map_lines, free);
	if (cfg->north_texture != NULL)
		ft_ptr_free(&cfg->north_texture);
	if (cfg->south_texture != NULL)
		ft_ptr_free(&cfg->south_texture);
	if (cfg->west_texture != NULL)
		ft_ptr_free(&cfg->west_texture);
	if (cfg->east_texture != NULL)
		ft_ptr_free(&cfg->east_texture);
}