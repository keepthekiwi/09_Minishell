/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:37:05 by nhaas             #+#    #+#             */
/*   Updated: 2022/02/24 14:56:40 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

static long long	blanks(const char *str)
{
	long long	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n')
	{
		i++;
		while (str[i] == ' ')
			i++;
	}
	return (i);
}

static long long	negativ(const char *str, long long i)
{
	long long	ret;

	ret = 1;
	if (str[i] == '-')
		ret *= -1;
	return (ret);
}

static long long	negativ_i(const char *str, long long i)
{
	if (str[i] == '-' || str[i] == '+')
		return (i + 1);
	else
		return (i);
}

static int	retu(unsigned long long ret, int minus)
{
	if (minus > 0)
	{
		if (ret > (unsigned long long)LLONG_MAX)
			return (-1);
		else
			return ((int)ret);
	}
	else if (minus < 0)
	{
		if (ret > (unsigned long long)LLONG_MIN)
			return (0);
		else
			return ((int)ret * (-1));
	}
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long			i;
	unsigned long long	ret;
	long long			minus;

	i = blanks(str);
	minus = negativ(str, i);
	i = negativ_i(str, i);
	ret = 0;
	while (true)
	{
		if ((str[i] > 57 || str[i] < 48) && minus > 0)
		{
			return (retu(ret, minus));
		}
		else if ((str[i] > 57 || str[i] < 48) && minus < 0)
		{
			return (retu(ret, minus));
		}
		ret *= 10;
		ret += str[i] - 48;
		i++;
	}
}
