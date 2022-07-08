/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:59:39 by nhaas             #+#    #+#             */
/*   Updated: 2022/06/08 12:04:45 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*ptr;

	if (s == NULL)
		return (NULL);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (start > len)
	{
		ptr[0] = '\0';
		return (ptr);
	}
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
