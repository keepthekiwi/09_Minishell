/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:18:49 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/07 02:24:07 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minishell.h"

int	set_env_var(struct s_expander *vars, int pos, t_token *token)
{
	while (token->str[vars->len_env_var] != '\0' && \
		token->str[pos + vars->len_env_var] != ' ')
		vars->len_env_var++;
	vars->tmp_env_var = ft_calloc((vars->len_env_var + 2), \
							sizeof(*vars->tmp_env_var));
	vars->i = pos + 1;
	vars->j = 0;
	while (vars->j < vars->len_env_var - 1)
	{
		vars->tmp_env_var[vars->j++] = token->str[vars->i++];
	}
	vars->tmp_env_var[vars->len_env_var + 1] = '\0';
	return (0);
}

int	allocate_env(struct s_expander *vars,
	t_minishell *minishell, t_token *token, int pos)
{
	vars->tmp = ft_getenv(vars->tmp_env_var, minishell->env_list);
	if (!vars->tmp)
		return (-1);
	vars->env_var = vars->tmp->content;
	if (vars->env_var == NULL)
		return (-1);
	vars->len += ft_strlen(vars->env_var);
	vars->i = pos + vars->len_env_var;
	while (token->str[vars->i++] != '\0')
		vars->len++;
	vars->tmp_str = ft_calloc(vars->len + 1, sizeof(*vars->tmp_str));
	if (vars->tmp_str == NULL)
		return (-1);
	return (0);
}

void	insert_env_routine(struct s_expander *vars, t_token *token, int pos)
{
	while (token->str[vars->i] != '$')
	{
		vars->tmp_str[vars->i] = token->str[vars->i];
		vars->i++;
	}
	vars->j = 0;
	while (vars->j != ft_strlen(vars->env_var))
	{
		vars->tmp_str[vars->i] = vars->env_var[vars->j];
		vars->i++;
		vars->j++;
	}
	vars->j = pos + vars->len_env_var;
	while (vars->i != vars->len)
	{
		vars->tmp_str[vars->i] = token->str[vars->j];
		vars->i++;
		vars->j++;
	}
}

int	insert_env_var(t_token *token, t_minishell *minishell, int pos)
{
	struct s_expander	vars;

	init_vars(&vars);
	token->str = remove_quotes_new(token->str);
	vars.len = 0;
	vars.len += pos;
	vars.len_env_var = 0;
	if (set_env_var(&vars, pos, token) == -1)
		return (free_expander_vars(vars));
	if (allocate_env(&vars, minishell, token, pos) == -1)
		return (free_expander_vars(vars));
	vars.i = 0;
	insert_env_routine(&vars, token, pos);
	free(token->str);
	token->str = vars.tmp_str;
	if (vars.tmp_env_var)
		free(vars.tmp_env_var);
	return (0);
}

void	expander(t_minishell *minishell)
{
	char		*tmp_str;
	int			i;
	t_type		type;
	t_token		*tmp_token;

	tmp_token = minishell->pre_parsed;
	type = NOTSET;
	while (tmp_token != NULL)
	{
		i = 0;
		tmp_str = tmp_token->str;
		while (tmp_str[i] != '\0')
		{
			fflush(stdout);
			tmp_str = tmp_token->str;
			type = get_type(tmp_str[i], type);
			if (tmp_str[i] == '$' && type == DQUOTE)
				insert_env_var(tmp_token, minishell, i - 1);
			if (tmp_str[i] == '$' && type != SQUOTE)
				insert_env_var(tmp_token, minishell, i);
			++i;
		}
		tmp_token = tmp_token->next;
	}
}
