/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:57:25 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/29 20:30:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

typedef struct s_mlx_image
{
	int 	pixel_bits;
	int 	line_bytes;
	int 	endian;
	void	*image;
	
}	t_mlx_image;

#endif