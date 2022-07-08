/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:41:15 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 14:41:21 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_rd_type	check_rd_type(t_token *tmp_token)
{
	if (tmp_token->type != SREDIRECTION && tmp_token->type != DREDIRECTION)
		return (NONE);
	if (ft_strcmp(tmp_token->str, "<") == 0)
		return (RD_STDIN);
	else if (ft_strcmp(tmp_token->str, ">") == 0)
		return (RD_STDOUT);
	else if (ft_strcmp(tmp_token->str, ">>") == 0)
		return (DRD_STDOUT);
	else
		return (NONE);
}

char	*get_pwd(t_minishell *minishell)
{
	t_env	*env;

	env = minishell->env_list;
	while (env != NULL && ft_strcmp(env->name, "PWD") != 0)
		env = env->next;
	return (ft_strdup(env->content));
}

t_token	*get_redirection(t_minishell *minishell)
{
	t_token	*tmp_token;
	t_token	*rd_token;

	rd_token = NULL;
	tmp_token = minishell->current_token;
	while (tmp_token != NULL && tmp_token->type != PIPE)
	{
		if (tmp_token->type == SREDIRECTION || tmp_token->type == DREDIRECTION)
			rd_token = tmp_token;
		tmp_token = tmp_token->next;
	}
	return (rd_token);
}

int	is_there_rd(t_token *rd_token)
{
	while (rd_token != NULL && rd_token->type != PIPE)
	{
		if (rd_token->type == SREDIRECTION || rd_token->type == DREDIRECTION)
			return (1);
		rd_token = rd_token->next;
	}
	return (0);
}

int	ret_perror(char *str, int err)
{
	char	*tmp_str;

	if (err != 0)
		errno = err;
	tmp_str = ft_strjoin("minishell: ", str);
	perror(tmp_str);
	free(tmp_str);
	g_error_code = 1;
	return (-1);
}
