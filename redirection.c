/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:21:16 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:54:28 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_mulit_stdout_rd_stdout(t_minishell *minishell,
	char *file_path, t_token *tmp_token)
{
	file_path = ft_strjoin(get_pwd(minishell), ft_strjoin("/", tmp_token->str));
	minishell->rd_fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC);
	if (minishell->rd_fd < 0)
	{
		perror("minishell");
		return ;
	}
	if (is_there_rd(tmp_token) == 1)
		close(minishell->rd_fd);
}

void	handle_mulit_stdout_rd_stdin(t_minishell *minishell,
	char *file_path, t_token *tmp_token)
{
	file_path = ft_strjoin(get_pwd(minishell), ft_strjoin("/", tmp_token->str));
	minishell->rd_fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND);
	if (minishell->rd_fd < 0)
	{
		perror("minishell");
		return ;
	}
	if (is_there_rd(tmp_token) == 1)
		close(minishell->rd_fd);
}

t_token	*get_next_rd(t_token *tmp_token)
{
	while (tmp_token != NULL && tmp_token->type != SREDIRECTION
		&& tmp_token->type != DREDIRECTION)
		tmp_token = tmp_token->next;
	return (tmp_token->next);
}

void	handle_multi_stdout_rd(t_minishell *minishell)
{
	t_token		*tmp_token;
	char		*file_path;
	t_rd_type	rd_type;

	file_path = NULL;
	tmp_token = minishell->current_token;
	while (tmp_token != NULL && tmp_token->type != PIPE
		&& tmp_token->type != SREDIRECTION && tmp_token->type == DREDIRECTION)
		tmp_token = tmp_token->next;
	while (tmp_token != NULL && tmp_token->type != PIPE)
	{
		if (is_there_rd(tmp_token) == 0)
			break ;
		else
			get_next_rd(tmp_token);
			tmp_token = tmp_token->next;
		rd_type = check_rd_type(tmp_token->before);
		if (tmp_token == NULL || tmp_token->type == PIPE)
			break ;
		if (rd_type == RD_STDOUT)
			handle_mulit_stdout_rd_stdout(minishell, file_path, tmp_token);
		else if (rd_type == DRD_STDOUT)
			handle_mulit_stdout_rd_stdin(minishell, file_path, tmp_token);
	}
}

void	handle_stdout_rd_stdout(t_minishell *minishell)
{
	handle_multi_stdout_rd(minishell);
	if (dup2(minishell->rd_fd, STDOUT_FILENO) == -1)
		perror("minishell");
}
