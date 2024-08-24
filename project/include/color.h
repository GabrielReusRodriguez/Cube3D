/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:56:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 20:57:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

} t_color;

t_color	color_new(unsigned char _r, unsigned char _g, unsigned char _b);

#endif