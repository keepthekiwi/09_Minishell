/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:20:41 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:22:11 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_i_pipes_token(t_minishell *minishell)
{
	int		i;
	t_token	*token;

	i = 0;
	token = minishell->current_token;
	while (token != NULL)
	{
		if (token->type == PIPE)
			i++;
		token = token->next;
	}
	return (i);
}

int	setup_pipe(t_minishell *minishell, t_token *tmp_token)
{
	(void)tmp_token;
	if (pipe(minishell->fd) != 0)
	{
		perror("pipe");
		return (-1);
	}
	minishell->i_pipes--;
	return (0);
}

t_type	check_type_till_pipe(t_minishell *minishell)
{
	t_token	*tmp_token;

	tmp_token = minishell->current_token;
	while (tmp_token && tmp_token->type != PIPE)
	{
		if (tmp_token->type == CMD)
			return (CMD);
		else if (tmp_token->type == BUILTIN)
			return (BUILTIN);
		tmp_token = tmp_token->next;
	}
	return (NOTSET);
}
