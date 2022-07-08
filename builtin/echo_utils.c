/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:16:09 by skillian          #+#    #+#             */
/*   Updated: 2022/07/06 20:22:28 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_str_printer(char *str)
{
	int	len;
	int	i;

	i = 0;
	if (*str == '\'' || *str == '\"')
	{	
		len = ft_strlen(str);
		str++;
		len--;
		while (--len)
		{
			write(STDOUT_FILENO, &str[i], 1);
			str++;
		}
	}
}

void	echo_errorcode_cmd_printer(char *str)
{
	char	*error_str;

	error_str = ft_itoa(g_error_code);
	write(STDOUT_FILENO, error_str, \
	ft_strlen(error_str));
	free(error_str);
	if (str[2])
		write(STDOUT_FILENO, str + 2, \
		ft_strlen(str + 2));
	return ;
}

void	norminette_is_your_friend(char *str)
{
	if (*str == '\'' || *str == '\"')
		quote_str_printer(str);
	else if (ft_strncmp("$?", str, 2) == 0)
		echo_errorcode_cmd_printer(str);
	else
		write(STDOUT_FILENO, str, ft_strlen(str));
	return ;
}

//export t"est"10 verbre "v nrnkjerwiv" cvvcrebvj''