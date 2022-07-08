/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:14:11 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 12:42:11 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_token *ptr_list)
{
	bool	option;

	option = false;
	if (!ptr_list)
	{
		printf("\n");
		return (0);
	}
	if (ptr_list && ptr_list->type == OPTION)
	{
		option = echo_n_option_checker(ptr_list->str);
		ptr_list = ptr_list->next;
	}
	while (ptr_list && (ptr_list->type > 3 && ptr_list->type <= 9))
	{	
		norminette_is_your_friend(ptr_list->str);
		ptr_list = ptr_list->next;
		if (ptr_list && ptr_list->space)
			write(STDOUT_FILENO, " ", 1);
	}
	if (!option)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

bool	char_checker(char *check, char c)
{
	check++;
	while (*check)
	{
		if (ft_strncmp(check, &c, 1) == 0)
			check++;
		else
			return (false);
	}
	return (true);
}

bool	echo_n_option_checker(char *str)
{
	if ((ft_strncmp(str, "-n", 3) == 0) || \
		(*str == '-' && char_checker(str, 'n')))
		return (true);
	else
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		write(STDOUT_FILENO, " ", 1);
		return (false);
	}
}
