/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:35:13 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/30 13:20:42 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_nbrlen(int n)
{
	long int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_ifneg(int n)
{
	char		*chr;
	long int	len;

	n *= (-1);
	len = ft_nbrlen(n);
	len++;
	chr = malloc(sizeof(char) * (len + 1));
	if (chr == NULL)
		return (NULL);
	chr[len] = '\0';
	chr[0] = '-';
	len--;
	while (len >= 1)
	{
		chr[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (chr);
}

static char	*ft_ifpos(int n)
{
	char		*chr;
	long int	len;

	len = ft_nbrlen(n);
	chr = malloc(sizeof(char) * (len + 1));
	if (chr == NULL)
		return (NULL);
	chr[len] = '\0';
	len--;
	while (len >= 0)
	{
		chr[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (chr);
}

char	*ft_itoa(int n)
{
	char		*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(12 * sizeof(char));
		ptr = ft_memmove(ptr, "-2147483648", 12);
		return (ptr);
	}
	else if (n == 0 || n == -0)
	{
		ptr = malloc(2 * sizeof(char));
		ptr = ft_memmove(ptr, "0", 2);
		return (ptr);
	}
	else if (n < 0)
		return (ft_ifneg(n));
	else if (n >= 0)
		return (ft_ifpos(n));
	else
		return (NULL);
}
