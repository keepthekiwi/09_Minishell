/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:15:51 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 15:01:08 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	equal_quotes_checker(char *input_str, int i)
{
	int	quotes[3];

	ft_bzero(&(quotes[0]), sizeof(int) * 3);
	while (input_str && input_str[i] != '\0')
	{
		if (input_str[i] == '\'' && quotes[2] == 0 && ++quotes[0])
			quotes[2] = 1;
		else if (input_str[i] == '\"' && quotes[2] == 0 && ++quotes[1])
			quotes[2] = 1;
		else if (input_str[i] == '\'' && quotes[2] == 1 && ++quotes[0])
			quotes[2] = 0;
		else if (input_str[i] == '\"' && quotes[2] == 1 && ++quotes[1])
			quotes[2] = 0;
		i++;
	}
	return ((quotes[0] % 2) + (quotes[1] % 2));
}

int	lexer(char *pos, t_minishell *minishell)
{
	char	*space_check;
	bool	space;

	while (*pos)
	{
		space = false;
		space_check = pos;
		pos = ignore_white_space(pos);
		if (space_check != pos)
			space = true;
		pos = extract_word_and_add_token(minishell, pos, space, false);
	}
	return (0);
}

void	check_operator(char **pos, bool *operator)
{
	*operator = false;
	if (**pos && operator_checker(*pos))
	{
		*operator = true;
		if (double_operator_checker(*pos))
			(*pos)++;
		(*pos)++;
	}
}

char	*extract_word_and_add_token(t_minishell *minishell, \
		char *pos, bool space, bool quotes)
{
	char	*word;
	char	*start;
	bool	operator;

	start = pos;
	check_operator(&pos, &operator);
	if (*pos && (*pos == '\'' || *pos == '\"') && operator == false)
	{
		if (pos_second_quote(pos) == false)
			return (0);
		pos = pos_second_quote(pos);
		quotes = true;
	}
	if (quotes == false && operator == false)
		while (*pos && !is_white_space_or_quote(pos) && !operator_checker(pos))
			pos++;
	word = create_word(pos, start);
	if (!empty_word_checker(word))
		create_token_and_add_to_list(minishell, word, space);
	else
		free (word);
	return (pos);
}

char	*create_word(char *pos, char *start)
{
	char	*word;

	word = malloc(sizeof(char) * (pos - start + 1));
	if (!word)
		return (NULL);
	word = ft_strlcpy_r(word, start, (pos - start + 1));
	return (word);
}
