/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_without_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:20:13 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:21:52 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	execute_without_pipes(t_minishell *minishell)
{
	t_token	*tmp_token;
	int		pid;

	tmp_token = minishell->pre_parsed;
	minishell->current_token = minishell->pre_parsed;
	if (is_there_rd(minishell->current_token) == 1)
	{
		if (handle_stdin_rd_without_pipes(minishell) == -1)
			return (-1);
		else if (handle_stdout_rd_without_pipes(minishell) == -1)
			return (-1);
	}
	if (minishell->i_pipes == 0 && check_type_till_pipe(minishell) == BUILTIN)
	{
		execute_builtin(tmp_token->str, tmp_token->next, minishell);
		return (0);
	}
	else if (minishell->i_pipes == 0 && check_type_till_pipe(minishell) == CMD)
	{
		pid = fork();
		if (pid == 0)
			execute_cmd(minishell);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
