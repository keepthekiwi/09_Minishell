/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:39:39 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 14:38:52 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*find_node_before(t_env *list, t_env *found)
{
	if (list->next == NULL)
		return (NULL);
	while (list)
	{
		if (found == list->next)
			return (list);
		list = list->next;
	}
	return (NULL);
}

bool	unset_validity_checker(char *str)
{
	char	*check_str;

	check_str = str;
	while (*check_str)
	{
		if (ft_strncmp(check_str, "_", 2) == 0)
			break ;
		if (!ft_isdigit(*check_str) && !ft_isalpha(*check_str))
		{
			printf("unset: `%s': not a valid identifier\n", str);
			g_error_code = 1;
			free(str);
			return (false);
		}
		check_str++;
	}
	return (true);
}

bool	secret_easter_egg(char *str)
{
	if (!ft_strcmp(str, "HOME") || \
	!ft_strcmp(str, "PATH") || !ft_strcmp(str, "TERM"))
	{
		printf("Congrats! You have unlocked a free softdrink :D\n");
		return (true);
	}
	free(str);
	return (false);
}

void	digit_not_valid_printer(char *str)
{
	printf("unset: `%s': not a valid identifier\n", str);
	g_error_code = 1;
}
