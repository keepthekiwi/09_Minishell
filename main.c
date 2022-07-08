/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:27:44 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 17:56:08 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

void	print_welcome_message(void)
{
	printf("%s|___|___|___|___|___|___|___|___|___|___|___|___|___|_\n", GREEN);
	printf("%s__|___|___|___|___|___|___|___|___|___|___|___|___|___\n", GREEN);
	printf("%s|___|___|___|___|___|___|___|___|___|___|___|___|___|_\n", GREEN);
	printf("%s__|__| |____________________________________________| \n", GREEN);
	printf("%s|_(__   ____________________________________________  \n", GREEN);
	printf("%s__|__| |                                            | \n", GREEN);
	printf("%s|___|| |         Made by skillian & nhaas           | \n", GREEN);
	printf("%s__|__| |       _____ _     _     _       _ _        | \n", GREEN);
	printf("%s|___|| |      |     |_|___|_|___| |_ ___| | |       | \n", GREEN);
	printf("%s__|__| |      | | | | |   | |_ -|   | -_| | |       | \n", GREEN);
	printf("%s|___|| |      |_|_|_|_|_|_|_|___|_|_|___|_|_|       | \n", GREEN);
	printf("%s__|__| |                                            | \n", GREEN);
	printf("%s|____| |____________________________________________| \n", GREEN);
	printf("%s__(__   ____________________________________________  \n", GREEN);
	printf("%s__|__| |__|___|___|___|___|___|___|___|___|___|___|_| \n", GREEN);
	printf("%s|___|___|___|___|___|___|___|___|___|___|___|___|___|_\n", GREEN);
	printf("%s__|___|___|___|___|___|___|___|___|___|___|___|___|___\n\n", GREEN);
}

void	init_minishell(t_minishell *minishell)
{
	print_welcome_message();
	minishell->cmds = NULL;
	minishell->pre_parsed = NULL;
	minishell->path = (char *) NULL;
	minishell->valid_cmd = false;
	minishell->pre_parsed_len = 0;
	minishell->i_cmds = 0;
	minishell->i_pipes = 0;
	minishell->env_arr = NULL;
	minishell->current_token = NULL;
	minishell->promt = NULL;
	minishell->user = NULL;
	minishell->home_path = NULL;
	minishell->env_list = NULL;
	g_error_code = 0;
	minishell->std_in = dup(STDIN_FILENO);
	minishell->std_out = dup(STDOUT_FILENO);
	return ;
}

int	start_executing(t_minishell *minishell, char *input)
{
	add_history(input);
	if (equal_quotes_checker(input, 0) != 0)
		return (ret_perror("quotes", 22));
	if (handle_input(minishell, input) == -1)
		return (ret_perror("empty argument", 22));
	if (minishell->valid_cmd == true)
		executer(minishell, input);
	free_pre_parsed(minishell);
	minishell->pre_parsed = NULL;
	minishell->cmds = NULL;
	dup2(minishell->std_in, STDIN_FILENO);
	dup2(minishell->std_out, STDOUT_FILENO);
	return (0);
}

void	minishell_routine(t_minishell *minishell, char **envp)
{
	char	*promt;
	char	*input;

	while (1)
	{
		handle_global_signals();
		promt = get_promt(minishell, envp);
		input = readline(promt);
		if (input == NULL)
			break ;
		free(promt);
		promt = NULL;
		if (input[0] != '\0')
			start_executing(minishell, input);
		free(input);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_minishell	minishell;

	argc = 0;
	argv = NULL;
	init_minishell(&minishell);
	ft_env_fetch_origin(&minishell, envp);
	minishell.env_arr = t_env_in_arr_convert(&minishell, 0);
	minishell_routine(&minishell, envp);
	close(minishell.std_in);
	close(minishell.std_out);
	return (0);
}
