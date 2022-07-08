/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:25:42 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:52:53 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	handle_stdin_rd_without_pipes_stdin(char *filename)
{
	int	test_fd;

	test_fd = open(filename, O_RDONLY, 0644);
	if (test_fd == -1)
		return (ret_perror("pipes stdin", 0));
	return (test_fd);
}

int	handle_stdin_rd_without_pipes(t_minishell *minishell)
{
	t_token	*tmp_token;
	char	*filename;
	int		test_fd;

	tmp_token = minishell->pre_parsed;
	while (tmp_token != NULL && is_there_rd(tmp_token) == 1)
	{
		tmp_token->rd_type = check_rd_type(tmp_token);
		if (tmp_token == NULL)
			return (0);
		if (tmp_token->rd_type != NONE)
			filename = tmp_token->next->str;
		if (tmp_token->rd_type == RD_STDIN)
			test_fd = handle_stdin_rd_without_pipes_stdin(filename);
		if (test_fd == -1)
			return (-1);
		tmp_token = tmp_token->next;
	}
	if (test_fd > -1 && handle_stdin_rd_without_pipes_pipe(minishell,
			tmp_token, test_fd) == -1)
		return (-1);
	return (1);
}

int	handle_stdout_rd_without_pipes_multi(t_token *tmp_token)
{
	char	*filename;
	int		test_fd;

	test_fd = 0;
	filename = NULL;
	tmp_token->rd_type = check_rd_type(tmp_token);
	if (tmp_token == NULL)
		return (0);
	if (tmp_token->rd_type != NONE)
		filename = tmp_token->next->str;
	if (tmp_token->rd_type == RD_STDOUT)
		test_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (tmp_token->rd_type == DRD_STDOUT)
		test_fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (test_fd);
}

int	handle_stdout_rd_without_pipes_dup(t_minishell *minishell,
	int test_fd, t_token *tmp_token)
{
	tmp_token = get_redirection(minishell);
	if (tmp_token != NULL && (tmp_token->rd_type == RD_STDOUT
			|| tmp_token->rd_type == DRD_STDOUT))
	{
		if (dup2(test_fd, STDOUT_FILENO) == -1)
			return (ret_perror("stdout pipe", 0));
		close(test_fd);
	}
	return (0);
}

int	handle_stdout_rd_without_pipes(t_minishell *minishell)
{
	int		test_fd;
	t_token	*tmp_token;

	tmp_token = minishell->pre_parsed;
	while (tmp_token != NULL && is_there_rd(tmp_token) == 1)
	{
		test_fd = handle_stdout_rd_without_pipes_multi(tmp_token);
		if (test_fd == -1)
			return (ret_perror("open 2", 0));
		tmp_token = tmp_token->next;
	}
	if (test_fd > -1)
		handle_stdout_rd_without_pipes_dup(minishell, test_fd, tmp_token);
	return (1);
}
