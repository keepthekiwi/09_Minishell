/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:24:16 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:51:18 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_stdout_rd(t_minishell *minishell)
{
	t_token		*redirection;

	redirection = get_redirection(minishell);
	if (redirection != NULL)
		redirection->rd_type = check_rd_type(redirection);
	if (check_i_pipes_token(minishell) > 0)
	{
		if (dup2(minishell->fd[1], STDOUT_FILENO) == -1)
			perror("minishell");
		close(minishell->fd[1]);
		return (0);
	}
	if (is_there_rd(minishell->current_token) == 0)
		return (0);
	if (redirection->rd_type == RD_STDOUT)
		handle_stdout_rd_stdout(minishell);
	else if (redirection->rd_type == DRD_STDOUT)
		handle_stdout_rd_stdout(minishell);
	close(minishell->rd_fd);
	close(minishell->fd[1]);
	return (1);
}

int	handle_stdin_rd_stdin(t_minishell *minishell, char *filename)
{
	filename = ft_strjoin(get_pwd(minishell), ft_strjoin("/", filename));
	minishell->rd_fd = open(filename, O_RDONLY);
	if ((minishell->rd_fd) == -1)
		return (ret_perror("rd_stdin", 0));
	if (dup2(minishell->rd_fd, STDIN_FILENO) == -1)
		return (-1);
	close(minishell->rd_fd);
	return (0);
}

void	handle_stdin_rd_pipe(t_minishell *minishell)
{
	if (dup2(minishell->tmp_fd, STDIN_FILENO) == -1)
		ret_perror("pipe", 0);
	close(minishell->tmp_fd);
}

int	handle_stdin_rd(t_minishell *minishell)
{
	t_rd_type	rd_type;
	t_token		*redirection;
	char		*filename;

	rd_type = NONE;
	filename = NULL;
	redirection = get_redirection(minishell);
	if (redirection != NULL)
	{
		rd_type = check_rd_type(redirection);
		filename = redirection->next->str;
	}
	if (rd_type == RD_STDIN)
		handle_stdin_rd_stdin(minishell, filename);
	else
		handle_stdin_rd_pipe(minishell);
	return (1);
}

int	handle_stdin_rd_without_pipes_pipe(t_minishell *minishell,
	t_token *tmp_token, int test_fd)
{
	tmp_token = get_redirection(minishell);
	if (tmp_token != NULL && tmp_token->rd_type == RD_STDIN)
	{
		if (dup2(test_fd, STDIN_FILENO) == -1)
			return (ret_perror("pipes", 0));
		close(test_fd);
	}
	return (0);
}
