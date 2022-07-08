/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:53:57 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/28 11:09:04 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while (ptr_str1[i] == ptr_str2[i] && i != n - 1)
		i++;
	return (ptr_str1[i] - ptr_str2[i]);
}
/**
int	main (void)
{
	char str1[] = "This is also a string";
	char str2[] = "This is also c string";
	int ret;
	int ret2;
	ret = ft_memcmp(str1, str2, 20);
	ret2 = memcmp(str1, str2, 20);
	printf("\nft_memcmp.c ---------\n\n");
	printf("string 1: %s\nstring 2: %s\n\now: %d\nor: %d\n", str1, str2, ret, ret2);
	ret = ft_memcmp("t\200", "t\0", 2);
	ret2 = memcmp("t\200", "t\0", 2);

	printf("\now: %d\nor: %d\n\n",ret, ret2);
	return (0);
}
**/
