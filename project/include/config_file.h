/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:53:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 21:45:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_FILE_H
# define CONFIG_FILE_H

# include "types.h"
# include "color.h"
# include "libft.h"

typedef struct s_config_file
{
	char	**map;
	t_list	*map_lines;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	
}	t_config_file;

//config_file.c
bool	config_file_init(t_config_file *cfg, const char *filename);
void	config_file_destroy(t_config_file *cfg);

//config_file_loader.c
bool	config_file_load(t_config_file *cfg, int fd);

//config_header_parser.c
bool	config_file_parse_header(t_config_file *cfg, const char *line);

//config_map_parser.c
bool	config_file_parse_map(t_config_file *cfg, const char *line);

#endif