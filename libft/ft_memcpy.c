/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:39:21 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 15:05:18 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(char *dest, char *src, int i)
{
	int	j;

	if ((dest || src) == '\0')
		return (0);
	j = 0;
	while (j != i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}

/**
void main(){
	char dest1[20];
	char dest2[20];
	char src[] = "This is a test";
	int i = 4;
	printf("string: %s\n\n",src);
	ft_memcpy(dest1, src, i);
	memcpy(dest2, src, i);
	printf("ow: %s\n",dest1);
	printf("or: %s\n",dest2);
}
**/
