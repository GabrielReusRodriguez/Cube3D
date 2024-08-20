/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:12:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/20 22:26:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "engine.h"
#include "mlx.h"

//void	*mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
bool	engine_texture_load(const char *filename, t_texture *texture, t_engine engine)
{
//	texture->mlx_image = mlx_png_file_to_image(engine.mlx, (char *)filename, 
	texture->mlx_image = mlx_xpm_file_to_image(engine.mlx, (char *)filename, \
		&texture->width, &texture->height);
	if (texture->mlx_image == NULL)
		return (false);
	return (true);
}

bool	engine_textures_load(t_engine *engine)
{
	(void)engine;
	return (true);	
}
