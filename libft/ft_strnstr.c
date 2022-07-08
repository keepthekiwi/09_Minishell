/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:28:08 by nhaas             #+#    #+#             */
/*   Updated: 2021/07/19 15:20:19 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

static char	*ft_ret(const char *big, const char *little, int len)
{
	if (little == big)
		return ((char *)big);
	else if (little[0] == '\0')
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int		i[2];

	if (little == big || little[0] == '\0' || len == 0)
		return (ft_ret(big, little, len));
	if (len < 0)
	{
		i[0] = len;
		len = ft_strlen(big);
	}
	i[0] = 0;
	i[1] = 0;
	while (big[i[0]] != '\0' && i[0] < len)
	{
		i[1] = 0;
		while (big[i[0] + i[1]] == little[i[1]] && little[i[1]] != '\0')
		{
			if (little[i[1] + 1] == '\0' && i[0] + i[1] < len)
			{
				return ((char *)&big[i[0]]);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (NULL);
}
