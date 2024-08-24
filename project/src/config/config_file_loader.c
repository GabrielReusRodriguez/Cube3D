/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 21:41:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "error.h"
#include "libft.h"
#include "ft_get_next_line.h"


static bool config_file_is_header(const char *line)
{
	if (ft_strcncmp(line, "F ", 2) == 0)
		return (true);
	if (ft_strcncmp(line, "C ", 2) == 0)
		return (true);
	if (ft_strcncmp(line, "NO ", 3) == 0)
		return (true);
	if (ft_strcncmp(line, "SO ", 3) == 0)
		return (true);
	if (ft_strcncmp(line, "WE ", 3) == 0)
		return (true);
	if (ft_strcncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

static bool	config_file_parse_line(t_config_file *cfg, const char *line)
{
	if (config_file_is_header(line))
	{

	}
	return (true);	
}

bool	config_file_load(t_config_file *cfg, int fd)
{
	char *line;

	if (fd < 0)
		return (error_print_critical("Invalid .cub file"), false);
	line = ft_strdup("");
	if (line == NULL)
		return (error_perror_critical(), false);
	while (line != NULL)
	{
		free (line);
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
		{
			if (!config_file_parse_line(cfg, line))
				return (error_print_critical("Config option not supported") , false);
		}
	}
	return (true);
}