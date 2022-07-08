/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:12:58 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 15:50:31 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

char	*free_char_ret(char *free_str)
{
	free(free_str);
	return (NULL);
}

void	var_plus_content(t_minishell *minishell, char *str, t_env *list)
{
	char	*pos_equal;
	char	*var;
	char	*content;
	t_env	*tmp_env;

	pos_equal = ft_strchr(str, '=');
	var = ft_substr(str, 0, (pos_equal - str));
	content = ft_substr(str, (pos_equal + 1 - str), ft_strlen(str));
	tmp_env = search_in_env_list(list, var);
	if (tmp_env)
	{
		free(tmp_env->content);
		tmp_env->content = content;
		tmp_env->hidden = false;
	}
	if (!tmp_env)
	{
		create_env_node_add_to_list(minishell, var, false);
		tmp_env = search_in_env_list(list, var);
		tmp_env->content = content;
	}
	free(var);
}

int	ft_export(t_token *token, t_minishell *minishell)
{
	char	*str;

	g_error_code = 0;
	if (!token)
		return (export_cmd_printer(minishell));
	if (token->str[0] == '=' && !token->space)
		return (0);
	while (token)
	{
		str = add_words(&token);
		if (check_if_valid_identifier(str))
		{
			check_identifier(str);
			if (str && !ft_strchr((str + 1), '='))
			{
				if (!search_in_env_list(minishell->env_list, str))
					create_env_node_add_to_list(minishell, str, true);
			}
			else
				var_plus_content(minishell, str, minishell->env_list);
		}
		free(str);
		token = token->next;
	}
	return (0);
}

char	*remove_quotes(char *str)
{
	if (str == NULL)
		return (NULL);
	if (*str == '\"' || *str == '\'')
		str = ft_substr(str, 1, (ft_strlen(str) - 2));
	else
		str = ft_strdup(str);
	return (str);
}

char	*remove_quotes_new(char *str)
{
	char	*tmp_str;

	tmp_str = NULL;
	if (str == NULL)
		return (NULL);
	if (*str == '\"' || *str == '\'')
		tmp_str = ft_substr(str, 1, (ft_strlen(str) - 2));
	else
		tmp_str = ft_strdup(str);
	free(str);
	return (tmp_str);
}
