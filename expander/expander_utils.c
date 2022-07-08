/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:25:06 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/07 02:18:04 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_type	get_type(char chr, t_type type)
{
	if (chr == '\"' && type == NOTSET)
		return (DQUOTE);
	else if (chr == '\"' && type == DQUOTE)
		return (NOTSET);
	else if (chr == '\'' && type == NOTSET)
		return (SQUOTE);
	else if (chr == '\'' && type == SQUOTE)
		return (NOTSET);
	return (type);
}

int	free_expander_vars(struct s_expander vars)
{
	free(vars.env_var);
	free(vars.tmp_env_var);
	free(vars.tmp_str);
	return (0);
}
