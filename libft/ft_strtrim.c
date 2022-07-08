/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:26:13 by nhaas             #+#    #+#             */
/*   Updated: 2021/07/19 15:20:42 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_whitespace(char const *set, char const *str, int j)
{
	int	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == str[j])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new_str;

	if (s1 == NULL)
		return (NULL);
	if (set[0] == '\0')
		return (ft_strdup((char *)s1));
	i = 0;
	while (ft_whitespace(set, s1, i) == 1)
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_whitespace(set, s1, j) == 1)
		j--;
	new_str = malloc((ft_strlen(&s1[i]) - ft_strlen(&s1[j]) + 1)
			* sizeof(char));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_memcpy(new_str, (char *)&s1[i],
			ft_strlen(&s1[i]) - ft_strlen(&s1[j]) + 1);
	return (new_str);
}
