/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 07:46:09 by nhaas             #+#    #+#             */
/*   Updated: 2022/02/24 15:25:15 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *)src));
	else if (src == 0 || dest == 0)
		return (0);
	i = 0;
	while (src[i] != '\0' && i != size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen((char *)src));
}

/**
int	main ()
{
	char src[] = "This is a string";
	char dest1[20];
	char dest2[20];

	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	printf("string src: %s\n\now: %s\nor: %s", src, dest1, dest2);

	return (0);
}
**/
