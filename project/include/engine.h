/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:43:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/30 21:14:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "screen.h"
# include "camera.h"
# include "map.h"
# include "texture.h"
# include "config.h"

enum e_engine_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum	e_engine_textures
{
	TEXTURE_NORTH = 0,
	TEXTURE_SOUTH = 1,
	TEXTURE_WEST = 2,
	TEXTURE_EAST = 3
};

typedef	struct s_engine
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	t_camera	camera;
	t_map		map;
	t_config	*cfg;
	t_screen	screen;
	t_texture	textures[4];

}	t_engine;

bool	engine_init(t_engine *engine, t_config *cfg);
bool	engine_start(t_engine *engine);
void	engine_loop(t_engine *engine);
void	engine_destroy(t_engine *engine);
bool	engine_clear_window(t_engine *engine);
bool	engine_get_screen_size(t_engine *engine);
int		engine_render(void *param);

bool	engine_texture_load(const char *filename, t_texture *texture, t_engine engine);
bool	engine_textures_load(t_engine *engine);

#endif