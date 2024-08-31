/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_destroy_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:04:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/31 19:25:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "engine.h"
#include "events.h"

int on_destroy(void *param)
{
	t_engine *engine;

	engine = (t_engine *)param;
	engine_destroy(engine);
	exit(EXIT_SUCCESS);
	return (0);
}