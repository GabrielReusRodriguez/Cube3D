/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:56:48 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 21:44:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include "engine.h"
# include "color.h"

typedef struct s_frame
{
	int 	pixel_bits;
	int 	line_bytes;
	int 	endian;
//	void	*image;
	mlx_image_t	*image;
	char	*buffer;

}	t_frame;

//engine/frame.c
bool	frame_init(t_engine *engine, t_frame *frame);
void	frame_destroy(t_engine *engine, t_frame *frame);
void	frame_set_pixel(t_frame *frame, t_color color, t_point point);
void	frame_set_pixel_int(t_engine *engine, t_frame *frame, int color, t_point point);

#endif