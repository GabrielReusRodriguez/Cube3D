/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/18 21:20:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "cub3d.h"
#include "engine.h"

int	main(int argc, char **argv)
{
	t_engine	engine;

	(void)argc;
	(void)argv;
	if (!engine_init(&engine))
	{
		printf("ERROR al inicializar minilibx\n");
		return (EXIT_FAILURE);
	}
	if (!engine_new_window(&engine))
	{
		printf("ERROR al inicializar la ventana\n");
		return (EXIT_FAILURE);
	}
	engine_loop(&engine);
	engine_destroy(&engine);
	
	printf("Hola mundo!\n");
	return (EXIT_SUCCESS);
}
