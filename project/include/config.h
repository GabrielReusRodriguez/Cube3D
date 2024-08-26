/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:53:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/26 22:01:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "types.h"
# include "color.h"
# include "libft.h"

typedef struct s_config
{
	char	**map;
	t_list	*map_lines;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	
}	t_config;

//config.c
bool	config_init(t_config *cfg, const char *filename);
void	config_destroy(t_config *cfg);
bool	config_is_header_initialized(t_config config);

//config_loader.c
bool	config_load(t_config *cfg, int fd);

//config_header_parser.c
bool	config_parse_header(t_config *cfg, int fd);

//config_map_parser.c
bool	config_parse_map(t_config *cfg, int fd);
void	config_debug(t_config cfg);

#endif