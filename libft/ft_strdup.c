/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:26:23 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/28 11:41:56 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ptr = malloc ((sizeof(char) * (i + 1)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/**
int	main (void)
{
	char	src[] = "String";
	char	*dest;
	char	*dest2;

	dest = ft_strdup(src);
	dest2 = strdup(src);

	printf("--- ft_strdup.c ------------------\n\n");
	printf("src string: %s\ndest ow: %s\ndest or: %s\n\n", src, dest, dest2);
	return (0);
}
**/
