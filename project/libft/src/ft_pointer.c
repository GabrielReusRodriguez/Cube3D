/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:46:11 by greus-ro          #+#    #+#             */
/*   Updated: 2024/08/25 13:54:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_ptr_free(void *ptr)
{
	if (ptr != NULL)
		free (ptr);
	return (NULL);
}

char	*ft_ptr_new_char_buffer(size_t size)
{
	char	*buffer;

	buffer = ft_calloc(size + 1, 1);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}
