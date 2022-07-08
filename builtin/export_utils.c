/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:37:26 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 15:50:14 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

void	check_identifier(char *str)
{
	if (*str == '=' || ft_isdigit(*str))
	{
		printf("export: `%s': not a valid identifier\n", str);
		g_error_code = 1;
	}
}

t_env	*search_in_env_list(t_env *node, char *input)
{
	while (node)
	{
		if (ft_strncmp(node->name, input, ft_strlen(node->name) + 1) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	export_cmd_printer(t_minishell *minishell)
{
	t_env	*list;

	list = minishell->env_list;
	while (list)
	{
		if (list->content)
			printf("declare -x %s=\"%s\"\n", list->name, list->content);
		else
			printf("declare -x %s\n", list->name);
		list = list->next;
	}
	return (0);
}

int	check_if_valid_identifier(char *str)
{
	char	*check_str;

	check_str = str;
	while (*check_str)
	{
		if (!ft_isdigit(*check_str) && !ft_isalpha(*check_str) \
		&& *check_str != '=' && *check_str != ' ' && *check_str != '_')
		{
			printf("export: `%s': not a valid identifier\n", str);
			g_error_code = 1;
			return (0);
		}
		check_str++;
	}
	return (1);
}

char	*add_words(t_token **token)
{
	bool	first_word;
	char	*tmp_str;
	char	*str_clear;
	char	*str;

	first_word = true;
	str = remove_quotes((*token)->str);
	while ((*token)->next && (first_word || (*token
				&& !(*token)->space)) && !((*token)->next->space))
	{
		first_word = false;
		*token = (*token)->next;
		str_clear = remove_quotes((*token)->str);
		tmp_str = ft_strjoin(str, str_clear);
		free(str);
		if (!tmp_str)
			return (free_char_ret(str_clear));
		str = tmp_str;
		free(str_clear);
	}
	return (str);
}
