/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:18:27 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 14:16:51 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	int		*ptr;

	ptr = malloc (nitems * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

/**
int main(void)
{
	int nitems = 4;
	int size = 5;
	int *point1;
	int *point2;
	point1 = ft_calloc(nitems, sizeof(int));
	point2 = calloc(nitems, sizeof(int));
	*(point1+0) = 10;
	*(point1+1) = 20;
	*(point1+2) = 30;
	*(point2+0) = 10;
	*(point2+1) = 20;
	*(point2+2) = 30;

	printf("%u\n", point1);
	printf("%u", point2);
	return (0);
}
**/
