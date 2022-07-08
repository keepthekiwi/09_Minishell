/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:56:24 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/07 15:09:19 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	if (str[0] == '\0' && c == '\0')
		return (str);
	else if (str[0] == '\0' && c != '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && c != '\0')
		{
			return (&str[i]);
		}
		else if (c == '\0' && str[i + 1] == '\0')
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}

/**
int main()
{
	char	str[] = "This is a string";
	char	c = 'a';
	char	*ret;

	ret = ft_strchr(str, c);
	printf("string: %s\nchr: %c\n\now: %s\n", str, c, ret);
	ret = strchr(str, c);
	printf("or: %s\n", ret);
	return (0);
}
**/
