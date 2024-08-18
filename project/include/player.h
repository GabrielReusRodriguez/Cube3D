/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:29:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/18 18:43:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"
# include "point.h"

# define ANGLE_OF_VISION	45.0f

typedef	struct s_player
{
	t_point		position;
//	float		angle_orientation;
	t_vector	orientation;
	
}	t_player;

#endif