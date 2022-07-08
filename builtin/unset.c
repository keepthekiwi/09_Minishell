/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:14:50 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 17:45:19 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	search_and_unset(char *str, t_env **list)
{
	t_env	*found;

	if (unset_validity_checker(str))
	{
		if (ft_isdigit(*str))
			digit_not_valid_printer(str);
		else
		{	
			found = search_in_env_list(*list, str);
			if (found)
			{
				get_it_out_of_list(list, found);
				feel_free_node_env(found);
			}
		}
	}
	return (1);
}

int	ft_unset(t_token *token, t_env *list)
{
	char	*str;

	if (!token)
		return (0);
	while (token && token->type != PIPE)
	{
		str = add_words(&token);
		search_and_unset(str, &list);
		str = NULL;
		token = token->next;
	}
	return (0);
}

void	get_it_out_of_list(t_env **list, t_env *found)
{	
	t_env	*before;

	before = NULL;
	before = find_node_before(*list, found);
	if (before)
		before->next = found->next;
	else
		*list = found->next;
	return ;
}	
