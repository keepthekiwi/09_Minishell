/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:14:50 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 12:22:29 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	if ((ptr_str1 || ptr_str2) == 0)
		return (NULL);
	i = 0;
	if (ptr_str1 < ptr_str2)
	{
		while (i != n)
		{
			ptr_str1[i] = ptr_str2[i];
			i++;
		}
	}
	while (n > 0 && str1 > str2)
	{
		ptr_str1[n - 1] = ptr_str2[n - 1];
		n--;
	}
	return ((void *)str1);
}

/**
int main(){
	char str1[] = "Das ist ein String";
	char str2[] = "This is a string";
	char str3[] = "Das ist ein String";
	char str4[] = "This is a string";
	int n = 4;

	printf("string 1: %s\n",str1);
	printf("string 2: %s\n\n",str2);

	ft_memmove(str1, str2, n);
	memmove(str3, str4, n);

	printf("ow: %s\n", str1);
	printf("or: %s\n", str3);
	return(0);
}
**/
