/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:39:18 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/28 12:12:01 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		i;
	char	*ret;

	ret = 0;
	i = 0;
	if (str[0] == '\0' && c == '\0')
		return (str);
	else if (str[0] == '\0' && c != '\0')
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c && c != '\0')
			ret = &str[i];
		else if (str[i + 1] == c && c == '\0')
			ret = &str[i + 1];
		i++;
	}
	return (ret);
}

/**
int main()
{
	char str[] = "abtcabcabc";
	char c = 'a';
	char *ret;

	ret = ft_strrchr(str, c);
	printf("string: %s\nchr: %c\n\now: %s\n", str, c, ret);
	ret = strrchr(str, c);
	printf("or: %s\n", ret);
	return (0);
}
**/
