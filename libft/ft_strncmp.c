/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:25:59 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/25 12:01:26 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int				i;
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	i = 0;
	while (ptr_str1[i] == ptr_str2[i] && i != n - 1
		&& (ptr_str1[i] && ptr_str2[i]) != '\0')
	{
		i++;
	}
	if (n == 0)
		return (0);
	else
		return (ptr_str1[i] - ptr_str2[i]);
}

/**
int	main(void)
{
	char	str1[] = "This is also a string";
	char	str2[] = "This is also c string";
	int		ret;

	printf("string 1: %s\nstring 2: %s\n\n", str1, str2);
	ret = ft_strncmp(str1, str2, 20);
	printf("ow: %d",ret);
	printf("\n");
	ret = strncmp(str1, str2, 20);
	printf("or: %d",ret);
	printf("\n");
	return (0);
}
**/
