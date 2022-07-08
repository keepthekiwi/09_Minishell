/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_with_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:19:59 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:27:13 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	execute_child(t_minishell *minishell)
{
	t_token	*tmp_token;

	close(minishell->fd[0]);
	tmp_token = minishell->current_token;
	while (tmp_token != NULL && tmp_token->type != PIPE)
		tmp_token = tmp_token->next;
	handle_stdout_rd(minishell);
	handle_stdin_rd(minishell);
	if (check_type_till_pipe(minishell) == BUILTIN)
	{
		execute_builtin(minishell->current_token->str,
			minishell->current_token->next, minishell);
	}
	else if (check_type_till_pipe(minishell) == CMD)
		execute_cmd(minishell);
	exit(0);
}

void	execute_parent(t_minishell *minishell)
{
	t_token	*tmp_token;

	close(minishell->fd[1]);
	tmp_token = minishell->current_token;
	while (tmp_token != NULL && tmp_token->type != PIPE)
		tmp_token = tmp_token->next;
	if (tmp_token)
	{	
		if (dup2(minishell->fd[0], minishell->tmp_fd) == -1)
			perror("fd[0] -> tmp_fd");
	}
	close(minishell->fd[0]);
}

int	execute_with_pipes_routine(t_minishell	*minishell,
	t_token	*tmp_token)
{
	int	pid;

	while (tmp_token != NULL)
	{
		minishell->current_token = tmp_token;
		setup_pipe(minishell, tmp_token);
		pid = fork();
		if (pid == 0)
			execute_child(minishell);
		else
			execute_parent(minishell);
		while (tmp_token != NULL && tmp_token->type != PIPE)
		{
			tmp_token = tmp_token->next;
		}
		if (tmp_token != NULL && tmp_token->next != NULL
			&& tmp_token->type == PIPE)
			tmp_token = tmp_token->next;
		dup2(minishell->std_in, STDIN_FILENO);
		dup2(minishell->std_out, STDOUT_FILENO);
	}
	return (pid);
}

void	execute_with_pipes(t_minishell *minishell)
{
	int		i;
	int		pid;
	t_token	*tmp_token;
	int		stdin_tmp;

	i = 0;
	tmp_token = minishell->pre_parsed;
	minishell->tmp_fd = dup(STDIN_FILENO);
	if (minishell->tmp_fd == -1)
		perror("minishell");
	stdin_tmp = dup(STDIN_FILENO);
	pid = execute_with_pipes_routine(minishell, tmp_token);
	close(minishell->rd_fd);
	close(minishell->fd[0]);
	close(minishell->fd[1]);
	waitpid(pid, NULL, 0);
}
