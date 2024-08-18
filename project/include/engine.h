/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:43:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/18 21:17:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "types.h"
# include "screen.h"

# include "mlx.h"

typedef	struct s_engine
{
	void	*mlx;
	void	*mlx_win;

	t_screen	screen;

}	t_engine;

bool	engine_init(t_engine *engine);
bool	engine_new_window(t_engine *engine);
void	engine_loop(t_engine *engine);
void	engine_destroy(t_engine *engine);
bool	engine_clear_window(t_engine *engine);
bool	engine_get_screen_size(t_engine *engine);

#endif