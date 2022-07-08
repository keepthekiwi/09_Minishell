/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:05:48 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/30 11:33:21 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_subfunction(char *ptr, int len[2], char *s1, char *s2)
{
	int		i;

	i = 0;
	while (i != len[0])
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i != len[1])
	{
		ptr[len[0] + i] = s2[i];
		i++;
	}
	ptr[len[0] + len[1]] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		len[2];
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	len[0] = len_s1;
	len[1] = len_s2;
	ft_subfunction(ptr, len, (char *)s1, (char *)s2);
	return (ptr);
}

/**
int main(void)
{
	char s1[] = "Hello ";
	char s2[] = "World!";
	char *ptr = ft_strjoin(s1, s2);

	printf("--- ft_strjoin.c ------------------\n\n");
	printf("string 1: %s\nstring 2: %s\n\now: %s\n\n", s1, s2, ptr);
}
**/
