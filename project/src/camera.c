/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:43:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/22 21:10:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"


t_vector	camera_init_screen_plan(t_orientations orientation)
{
	if (orientation == NORTH || orientation == SOUTH)
		return (vector_init_values(FOV, 0.0f, false));
	else
		return (vector_init_values(0.0f, FOV, false));
}

t_camera	camera_init(t_point origin, t_orientations orientation)
{
	t_camera	camera;

	camera.position = origin;
	camera.camera_panel = camera_init_screen_plan(orientation);
	return (camera);

}

