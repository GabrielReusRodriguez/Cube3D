/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 20:38:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "engine.h"
#include "map.h"

int	main(int argc, char **argv)
{
	t_engine	engine;
	t_map		map;

	if (argc != 2)
		return (error_print_critical("Error: Incorrect number of params"), \
			EXIT_FAILURE);
	if (!map_load(&map, argv[1]))
		return (EXIT_FAILURE);
	if (!engine_init(&engine, &map))
		return (EXIT_FAILURE);
	if (!engine_start(&engine))
		return (EXIT_FAILURE);
	engine_loop(&engine);
	return (EXIT_SUCCESS);
}
