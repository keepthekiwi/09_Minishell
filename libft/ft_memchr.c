/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:17:39 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 15:06:11 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	const char	*ptr_str;

	ptr_str = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == c)
			return ((void *)&ptr_str[i]);
		i++;
	}
	return (NULL);
}

/*
int main()
{
	char str[] = "This is a string";
	char c = 's';
	int n = 10;

	char *ret;
	char *ret2;

	ret = ft_memchr(str, c, n);
	ret2 = memchr(str, c, n);

	printf("string: %s\n\now: %s\nor: %s\n", str, ret, ret2);

	return(0);
}
*/
