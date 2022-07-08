/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:45:44 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/28 11:06:38 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	while (src[j] != '\0' && (i + j) < size - 1)
	{
		dst[j + i] = src[j];
		j++;
	}
	if (i < size)
		dst[j + i] = '\0';
	return (i + ft_strlen(src));
}

/*
int main(void)
{
	char dest[30];

	ft_strlcat(dest, "lorem", 15);

	return (0);
}

int	main()
{
	char dst[40];
	char dst2[40];
	char src[30];

	dst[0] = 'h';
	dst[1] = 'e';
	dst[2] = 'l';
	dst[3] = 'l';
	dst[4] = 'o';
	dst[5] = ' ';
	dst2[6] = '\0';
	dst2[0] = 'h';
	dst2[1] = 'e';
	dst2[2] = 'l';
	dst2[3] = 'l';
	dst2[4] = 'o';
	dst2[5] = ' ';
	dst2[6] = '\0';
	src[0] = 'w';
	src[1] = 'o';
	src[2] = 'r';
	src[3] = 'l';
	src[4] = 'd';
	src[5] = '\0';

	printf("dest: %s\nsrc: %s\n\n", dst, src);
	ft_strlcat(dst, src, 20);
	strlcat(dst2, src, 20);
	printf("ow dest: %s\nor dest: %s\n", dst, dst2);
	return (0);
}
**/
