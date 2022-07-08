/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:15:16 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 14:20:47 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i != n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/**
int	main()
{
	char str[] = "asdfas929923";
	printf("string: %s \n\n",str);
	bzero(str,20);
	printf("or: %s \n",str);
	str[4] = "asdfas929923";
	ft_bzero(str,20);
	printf("ow: %s \n",str);

	return(0);
} **/
