/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:43:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/19 22:35:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "types.h"
# include "screen.h"
# include "player.h"
# include "map.h"

# include "mlx.h"

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

typedef	struct s_engine
{
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
	t_map		*map;
	t_screen	screen;
	void		**textures;

}	t_engine;

bool	engine_init(t_engine *engine, t_player *player, t_map *map);
bool	engine_start(t_engine *engine);
void	engine_loop(t_engine *engine);
void	engine_destroy(t_engine *engine);
bool	engine_clear_window(t_engine *engine);
bool	engine_get_screen_size(t_engine *engine);
int		engine_render(void *param);


#endif