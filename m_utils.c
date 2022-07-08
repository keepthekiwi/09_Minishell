/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:33:11 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 13:34:32 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	exit_minishell(t_minishell *minishell)
{
	free(minishell->promt);
	free(minishell->path);
	free_env_list(minishell);
	free_token_list(minishell);
	rl_clear_history();
}

void	count_cmds(t_minishell *minishell)
{
	t_token	*tmp_token;

	minishell->i_cmds = 0;
	minishell->i_pipes = 0;
	tmp_token = minishell->pre_parsed;
	while (tmp_token != NULL)
	{
		if (tmp_token->type == CMD || tmp_token->type == BUILTIN)
			minishell->i_cmds++;
		else if (tmp_token->type == PIPE)
			minishell->i_pipes++;
		tmp_token = tmp_token->next;
	}
}
