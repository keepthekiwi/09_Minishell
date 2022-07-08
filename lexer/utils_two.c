/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:36:55 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 14:40:22 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	is_white_space_or_quote(char *to_check)
{
	if (*to_check == ' ' || *to_check == '\t' || *to_check == '\v' \
	|| *to_check == '\f' || *to_check == '\r' || *to_check == '\'' \
	|| *to_check == '\"')
		return (true);
	return (false);
}

char	*ignore_white_space(char *pos)
{
	if (*pos == ' ' || *pos == '\t' || *pos == '\v' \
	|| *pos == '\f' || *pos == '\r')
		pos++;
	return (pos);
}

char	*ft_strlcpy_r(char *dest, const char *src, size_t size)
/* other return value, than original ft_function */
{
	size_t	i;

	if (size == 0)
		return (0);
	else if (src == 0 || dest == 0)
		return (0);
	i = 0;
	while (src[i] != '\0' && i != size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*pos_second_quote(char *pos)
{
	char	*start;

	start = pos;
	if (*pos == '\'' && ft_strchr(pos + 1, '\''))
	{
		pos = ft_strchr(pos + 1, '\'');
		return (pos + 1);
	}
	if (*pos == '\"' && ft_strchr(pos + 1, '\"'))
	{
		pos = ft_strchr(pos + 1, '\"');
		return (pos + 1);
	}
	return (false);
}

int	*create_token_and_add_to_list(t_minishell *minishell, \
	char *word, bool space)
{
	t_token	*token;
	t_token	*tmp;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->str = word;
	token->next = NULL;
	token->before = NULL;
	token->type = NOTSET;
	token->path = NULL;
	token->space = space;
	ft_lstadd_back_i(minishell->pre_parsed, token);
	if (minishell->pre_parsed == NULL)
		minishell->pre_parsed = token;
	else
	{
		tmp = minishell->pre_parsed;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (0);
}
