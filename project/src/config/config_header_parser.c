/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_header_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:41:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/25 13:53:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "libft.h"
#include "error.h"
#include "color.h"

static bool	config_set_texture(t_config_file *cfg, const char *line)
{
	size_t	length;
	char	*texture;

	length = ft_strlen(line);
	texture = ft_substr(line, 3, length - 3);
	if (texture == NULL)
		return (error_perror_critical(), false);
	if (ft_strncmp(line, "NO ", 3) == 0)
		cfg->north_texture = texture;
	if (ft_strncmp(line, "SO ", 3) == 0)
		cfg->south_texture = texture;
	if (ft_strncmp(line, "WE ", 3) == 0)
		cfg->west_texture = texture;
	if (ft_strncmp(line, "EA ", 3) == 0)
		cfg->east_texture = texture;
	return (true);
}

static	bool		config_parse_colors(t_color *color, const char *colors_line)
{
	char	**token_list;
	size_t	i;
	size_t	color_component;

	token_list = ft_split(colors_line, ",");
	if (token_list == NULL)
		return (error_perror_critical(), false);
	i = 0;
	while (token_list[i] != NULL)
	{
		color_component = ft_atoi(token_list[i]);
		if (i == 0)
			color->r = ft_atoi(token_list[i]);
		if (i == 1)
			color->g = ft_atoi(token_list[i]);
		if (i == 2)
			color->b = ft_atoi(token_list[i]);
		i++;
	}
	
}

static	bool	config_set_colors(t_config_file *cfg, const char *line)
{
	size_t	length;
	char	*colors;
	
	length = ft_strlen(line);
	colors = ft_substr(line, 2, length -2);
	if (colors == NULL)
		return (error_perror_critical(), false);
	
	return (true);
}

bool	config_file_parse_header(t_config_file *cfg, const char *line)
{

	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (config_set_colors(cfg, line));
	else
		return (config_set_texture(cfg,line));
}