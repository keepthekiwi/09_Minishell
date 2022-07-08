/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:36:35 by skillian          #+#    #+#             */
/*   Updated: 2022/06/30 10:36:39 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	operator_checker(char *pos)
{
	if (*pos == '|' || *pos == '>' || *pos == '<')
		return (true);
	return (false);
}

bool	double_operator_checker(char *pos)
{
	char	comparer;

	comparer = *pos;
	pos++;
	if (*pos == comparer)
		return (true);
	return (false);
}

bool	empty_word_checker(char *word_pos)
{
	long	len;
	long	space;

	len = 0;
	space = 0;
	while (*word_pos)
	{
		if (is_white_space_or_quote(word_pos))
			space++;
		len++;
		word_pos++;
	}
	if (len == space)
		return (true);
	else
		return (false);
}

t_token	*ft_lstlast_t_node(t_token *lst)
{
	int	i;

	if (lst == NULL)
		return (NULL);
	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_i(t_token *lst, t_token *new)
/* other input listname than original ft_funcion */
{
	t_token	*tmp_token;

	if (new == NULL)
		return ;
	if (lst == NULL)
		lst = new;
	else
	{
		tmp_token = lst;
		while (tmp_token->next != NULL)
			tmp_token = tmp_token->next;
		tmp_token->next = new;
		new->before = tmp_token;
	}
}
