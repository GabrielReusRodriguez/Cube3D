/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/05 19:21:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOODING_H
# define FLOODING_H

# include "types.h"
# include "config.h"

bool	flood_map(t_config config, bool *is_closed);


#endif