/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:31:22 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 17:45:02 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_vars(struct s_expander *vars)
{
	vars->env_var = NULL;
	vars->i = 0;
	vars->j = 0;
	vars->len = 0;
	vars->len_env_var = 0;
	vars->tmp = NULL;
	vars->tmp_env_var = NULL;
	vars->tmp_str = NULL;
}

void	free_pre_parsed(t_minishell *minishell)
{
	t_token	*tmp_token;
	t_token	*next_token;

	tmp_token = minishell->pre_parsed;
	while (tmp_token->next != NULL)
	{
		next_token = tmp_token->next;
		free(tmp_token->str);
		free(tmp_token->path);
		free(tmp_token);
		tmp_token = next_token;
	}
	free(tmp_token->str);
	free(tmp_token->path);
	free(tmp_token);
}

int	handle_input(t_minishell *minishell, char *input)
{
	lexer(input, minishell);
	if (minishell->pre_parsed == NULL)
		return (-1);
	expander(minishell);
	parser(minishell);
	return (0);
}
