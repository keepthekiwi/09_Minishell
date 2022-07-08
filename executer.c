/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:40:36 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 18:04:58 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

t_token	*get_cmd_token(t_minishell *minishell)
{
	t_token	*tmp_token;

	tmp_token = minishell->current_token;
	while (tmp_token != NULL)
	{
		if (tmp_token->type == CMD)
			return (tmp_token);
		tmp_token = tmp_token->next;
	}
	return (NULL);
}

void	execute_builtin(char *str, t_token *token, t_minishell *minishell)
{
	if (!str)
		return ;
	if (ft_strncmp(str, "echo", 5) == 0)
		g_error_code = ft_echo(token);
	else if (ft_strncmp(str, "cd", 3) == 0)
		g_error_code = ft_cd(token, minishell);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		ft_pwd();
	else if ((ft_strncmp(str, "export", 7) == 0)
		|| (ft_strncmp(str, "EXPORT", 7) == 0))
	{
		ft_export(token, minishell);
	}
	else if (ft_strncmp(str, "unset", 6) == 0)
		g_error_code = ft_unset(token, minishell->env_list);
	else if (ft_strncmp(str, "env", 4) == 0)
		env_printer(minishell);
	else if (ft_strncmp(str, "exit", 5) == 0)
	{
		exit_minishell(minishell);
		exit(0);
	}
}

void	execute_cmd(t_minishell *minishell)
{
	t_token	*cmd_token;
	char	**env;

	lst_converter(minishell);
	cmd_token = get_cmd_token(minishell);
	env = t_env_in_arr_convert(minishell, 0);
	if (execve(cmd_token->path, cmd_token->cmd_str, env) == -1)
	{
		perror("minishell: execve:");
		exit(EXIT_FAILURE);
	}
}

void	executer(t_minishell *minishell, char *input)
{
	(void)input;
	count_cmds(minishell);
	handle_cmd_signals();
	if (minishell->i_pipes == 0)
	{
		execute_without_pipes(minishell);
		return ;
	}
	else
		execute_with_pipes(minishell);
	handle_global_signals();
}
