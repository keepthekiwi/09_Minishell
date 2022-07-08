/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:19 by skillian          #+#    #+#             */
/*   Updated: 2022/07/06 18:30:40 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_type2(t_minishell *minishell, t_token **token)
{
	if ((*token)->before != NULL && ((*token)->before->type == BUILTIN \
			|| (*token)->before->type == CMD))
		(*token)->type = ARG;
	else if (token && check_is_buildin((*token)->str) == true)
	{
		(*token)->type = BUILTIN;
	}
	else if (token && (((*token)->before != NULL
				&& (*token)->before->type != SREDIRECTION
				&& (*token)->before->type != DREDIRECTION)
			|| (*token)->before == NULL)
		&& check_is_cmd(minishell, *token) == true)
	{
		(*token)->type = CMD;
	}
	else if (token)
		(*token)->type = ARG;
}

int	set_type(t_minishell *minishell, t_token *token)
{
	if (token->str[0] == '\"')
		token->type = DQUOTE;
	else if (token->str[0] == '\'')
		token->type = SQUOTE;
	else if (ft_strncmp(token->str, "|", 1) == 0)
		token->type = PIPE;
	else if ((ft_strncmp(token->str, "<<", 2) == 0
			|| ft_strncmp(token->str, ">>", 2) == 0)
		&& ft_strlen(token->str) == 2)
		token->type = DREDIRECTION;
	else if (((ft_strncmp(token->str, "<", 1) == 0)
			|| (ft_strncmp(token->str, ">", 1) == 0))
		&& ft_strlen(token->str) == 1)
		token->type = SREDIRECTION;
	else if (token->str[0] == '-')
		token->type = OPTION;
	else
		set_type2(minishell, &token);
	if (token->type != NOTSET)
		return (0);
	else
		return (-1);
}

void	set_cmd_path(t_minishell *minishell)
{
	t_token	*tmp_token;

	tmp_token = minishell->pre_parsed;
	while (tmp_token != NULL)
	{
		if (tmp_token->type == CMD)
			tmp_token->path = get_bin_path(minishell, tmp_token);
		tmp_token = tmp_token->next;
	}
}
