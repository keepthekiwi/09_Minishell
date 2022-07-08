/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:37:40 by skillian          #+#    #+#             */
/*   Updated: 2022/07/06 18:28:52 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_type_order_sub2(t_token *tmp_token)
{
	if (tmp_token->type == PIPE && tmp_token->next->type != CMD
		&& tmp_token->next->type != BUILTIN)
		return (ret_perror("parsing", 2));
	if ((tmp_token->type == SREDIRECTION || tmp_token->type == DREDIRECTION)
		&& tmp_token->next->type != ARG)
		return (ret_perror("parsing", 2));
	return (0);
}

int	check_type_order(t_minishell *minishell)
{
	t_token	*tmp_token;

	tmp_token = minishell->pre_parsed;
	if (tmp_token->before == NULL && (tmp_token->type == ARG
			|| tmp_token->type == OPTION))
	{
		errno = 2;
		return (errno);
	}
	tmp_token = tmp_token->next;
	while (tmp_token != NULL)
	{
		check_type_order_sub1(tmp_token);
		check_type_order_sub2(tmp_token);
		tmp_token = tmp_token->next;
	}
	return (0);
}

size_t	get_len_cmd(t_minishell *minishell)
{
	t_token	*tmp_token;
	int		i;

	i = 0;
	tmp_token = minishell->current_token;
	while (tmp_token != NULL && tmp_token->type != PIPE)
	{
		if (tmp_token->type == CMD || tmp_token->type == BUILTIN
			|| (tmp_token->type == ARG
				&& tmp_token->before->type != SREDIRECTION
				&& tmp_token->before->type != DREDIRECTION)
			|| tmp_token->type == OPTION || tmp_token->type == DQUOTE
			|| tmp_token->type == SQUOTE)
		i++;
		tmp_token = tmp_token->next;
	}
	return (i);
}

void	lst_converter(t_minishell *minishell)
{
	char	**cmds_str;
	t_token	*tmp_token;
	int		i;

	cmds_str = ft_calloc((get_len_cmd(minishell) + 1), sizeof(char *));
	tmp_token = minishell->current_token;
	i = 0;
	while (tmp_token != NULL && tmp_token->type != PIPE)
	{
		if (tmp_token->type == CMD || (tmp_token->type == ARG
				&& (tmp_token->before->type != SREDIRECTION
					&& tmp_token->before->type != DREDIRECTION))
			|| tmp_token->type == OPTION || tmp_token->type == SQUOTE
			|| tmp_token->type == DQUOTE)
		{
			if (tmp_token->type == SQUOTE || tmp_token->type == DQUOTE)
				tmp_token->str = remove_quotes(tmp_token->str);
			cmds_str[i] = strdup(tmp_token->str);
			i++;
		}
		tmp_token = tmp_token->next;
	}
	cmds_str[i] = NULL;
	tmp_token = get_cmd_token(minishell);
	tmp_token->cmd_str = cmds_str;
}

void	parser(t_minishell *minishell)
{
	int	error;

	type_handling(minishell);
	error = check_type_order(minishell);
	if (error != 0)
	{
		printf("%s\n", "minishell: error while parsing");
		g_error_code = 127;
		minishell->valid_cmd = false;
	}
	else
		minishell->valid_cmd = true;
}
