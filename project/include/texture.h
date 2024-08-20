/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:48:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/20 22:22:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef	struct s_texture 
{
	int		width;
	int		height;
	char	*file_name;
	void	*mlx_image;
}	t_texture;

#endif