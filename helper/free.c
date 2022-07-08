/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:31:45 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 14:32:18 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env_list(t_minishell *minishell)
{
	t_env	*list;
	t_env	*to_free;

	list = minishell->env_list;
	while (list != NULL)
	{
		to_free = list;
		list = list->next;
		feel_free_node_env(to_free);
	}
	minishell->env_list = NULL;
}

void	feel_free_node_env(t_env *node)
{
	if (!node)
		return ;
	free(node->name);
	if (node->content)
		free(node->content);
	node->next = NULL;
	free(node);
	return ;
}

void	free_token_list(t_minishell *minishell)
{
	t_token	*list;
	t_token	*to_free;

	list = minishell->pre_parsed;
	while (list)
	{
		to_free = list;
		list = list->next;
		feel_free_node_token(to_free);
	}
}

void	feel_free_node_token(t_token *token)
{
	if (!token)
		return ;
	if (token->str)
		free(token->str);
	if (token->path)
		free(token->path);
	free(token);
	return ;
}
