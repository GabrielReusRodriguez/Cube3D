/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/19 22:39:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# include <X11/keysym.h>
# include <X11/X.h>

#include "events.h"
#include "engine.h"

int	on_keydown(int key_code, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	(void)engine;
	printf("Key pressed %d\n", key_code);
	if (key_code == XK_Escape)
		engine_destroy(engine);
	return (0);
}