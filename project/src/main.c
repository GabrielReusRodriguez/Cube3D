/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/22 20:54:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "cub3d.h"
#include "engine.h"

int	main(int argc, char **argv)
{
	t_engine	engine;
	t_map		map;

	(void)argc;
	(void)argv;
	if (!engine_init(&engine, &map))
	{
		printf("ERROR al inicializar minilibx\n");
		return (EXIT_FAILURE);
	}
	if (!engine_start(&engine))
	{
		printf("ERROR al inicializar la ventana\n");
		return (EXIT_FAILURE);
	}
	engine_loop(&engine);
	return (EXIT_SUCCESS);
}
