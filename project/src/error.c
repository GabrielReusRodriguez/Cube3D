/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:43:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/19 22:48:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "error.h"
#include "libft.h"

void	error_print_warning(const char *msg)
{
	ft_putendl_fd((char *)msg, STDOUT_FILENO);
}

void	error_print_critical(const	char *msg)
{
	ft_putendl_fd((char *)msg, STDERR_FILENO);
}

void	error_print_perror_warning(void)
{
	perror("ERROR: ");
}

void	error_perror_critical(void)
{
	perror("WARNING: ");
}
