/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:08:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/26 22:36:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "config.h"
#include "error.h"

static	void	config_init_vars(t_config *config)
{
	config->map = NULL;
	config->map_lines = NULL;
	config->north_texture = NULL;
	config->south_texture = NULL;
	config->east_texture = NULL;
	config->west_texture = NULL;
	config->ceiling_color.r = -1;
	config->ceiling_color.g = -1;
	config->ceiling_color.b = -1;
	config->floor_color.r = -1;
	config->floor_color.g = -1;
	config->floor_color.b = -1;
}

bool	config_is_header_initialized(t_config config)
{
	if (config.north_texture == NULL || config.south_texture == NULL || \
			config.east_texture == NULL || config.east_texture == NULL)
		return false;
	if (config.ceiling_color.r < 0 || config.ceiling_color.g < 0 || \
		config.ceiling_color.b < 0)
		return (false);
	if (config.floor_color.r < 0 || config.floor_color.g < 0 || \
		config.floor_color.b < 0)
		return (false);
	return (true);
}

bool	config_init(t_config *cfg, const char *filename)
{
	int fd;

	config_init_vars(cfg);
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		return (error_perror_critical(), false);
	if (!config_load(cfg, fd))
		return (close (fd), false);
	close (fd);
	return (true);
}

/*
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
*/

void	config_destroy(t_config *cfg)
{
	ft_ptr_free_double_ptr(cfg->map);
//	config_file_destroy_map(cfg);
	ft_lstclear(&cfg->map_lines, free);
	if (cfg->north_texture != NULL)
		cfg->north_texture = ft_ptr_free(cfg->north_texture);
	if (cfg->south_texture != NULL)
		cfg->south_texture = ft_ptr_free(cfg->south_texture);
	if (cfg->west_texture != NULL)
		cfg->west_texture = ft_ptr_free(cfg->west_texture);
	if (cfg->east_texture != NULL)
		cfg->east_texture = ft_ptr_free(cfg->east_texture);
}

#include <stdio.h>

void	config_debug(t_config cfg)
{

	t_list	*node;

	printf("DEBUG CONFIG********************************\n");
	printf("\t NO: %s\n", cfg.north_texture);
	printf("\t SO: %s\n", cfg.south_texture);
	printf("\t WE: %s\n", cfg.west_texture);
	printf("\t EA: %s\n", cfg.east_texture);
	printf("\n");
	printf("\t F %d, %d, %d\n", cfg.floor_color.r, cfg.floor_color.g, cfg.floor_color.b);
	printf("\t C %d, %d, %d\n", cfg.ceiling_color.r, cfg.ceiling_color.g, cfg.ceiling_color.b);
	printf("\n");
	printf("\t MAP LIST ***\n");
	node = cfg.map_lines;
	while (node!= NULL)
	{
		printf("\t\t%s", (char *)node->content);
		node = node->next;
	}
	printf("\n");
	printf("\t MAP LIST ***\n");
	printf("DEBUG CONFIG********************************\n");	
}

