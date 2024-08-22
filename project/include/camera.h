/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:35:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/22 22:51:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "types.h"
# include "point.h"
# include "vector.h"

# define FOV	0.66f

typedef struct s_camera
{
	t_point		position;
	t_vector	camera_panel;
} t_camera;

t_camera	camera_init(t_point origin, t_orientations orientation);

#endif