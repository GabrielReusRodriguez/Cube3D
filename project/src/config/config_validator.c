/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:24:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/27 21:45:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
//#include <stdlib.h>

#include "config.h"
#include "error.h"

static bool	config_validate_textures(t_config *cfg)
{
	int	fd;
	
	fd = open(cfg->north_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("North texture cannot be opened"), false);
	close (fd);
	fd = open(cfg->south_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("South texture cannot be opened"), false);
	close (fd);
	fd = open(cfg->west_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("West texture cannot be opened"), false);
	close (fd);
	fd = open(cfg->east_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("East texture cannot be opened"), false);
	close (fd);
	return (true);
}

static bool	config_validate_colors(t_config *cfg)
{
	if (cfg->ceiling_color.r < 0 || cfg->ceiling_color.r > 256)
		return (error_print_critical("Ceiling colour invalid"), false);
	if (cfg->ceiling_color.g < 0 || cfg->ceiling_color.g > 256)
		return (error_print_critical("Ceiling colour invalid"), false);
	if (cfg->ceiling_color.b < 0 || cfg->ceiling_color.b > 256)
		return (error_print_critical("Ceiling colour invalid"), false);
	if (cfg->floor_color.r < 0 || cfg->floor_color.r > 256)
		return (error_print_critical("Floor colour invalid"), false);
	if (cfg->floor_color.g < 0 || cfg->floor_color.g > 256)
		return (error_print_critical("Floor colour invalid"), false);
	if (cfg->floor_color.b < 0 || cfg->floor_color.b > 256)
		return (error_print_critical("Floor colour invalid"), false);
	return (true);
}

bool	config_validator(t_config *cfg)
{
	if (!config_validate_textures(cfg))
		return (false);
	if (!config_validate_colors(cfg))
		return (false);
	if (!config_validate_map(cfg))
		return (false);
	return (true);
}