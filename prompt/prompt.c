/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:35:27 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 15:35:56 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_path(t_minishell *minishell)
{
	(void)minishell;
}

char	*get_promt(t_minishell *minishell, char **envp)
{
	char	*user;
	char	*promt;
	char	*home_path;
	char	*tmp;

	(void)envp;
	printf("%s", CYAN);
	set_path(minishell);
	user = ft_strjoin("\033[1m", getenv("USER"));
	home_path = getenv("HOME");
	promt = ft_strjoin(user, "@minishell:$");
	free(user);
	tmp = ft_strjoin(promt, home_path);
	free(promt);
	promt = ft_strjoin(tmp, " ▶️ ");
	free(tmp);
	tmp = ft_strjoin(promt, "\033[0m");
	free(promt);
	minishell->home_path = home_path;
	minishell->user = user;
	printf("%s", RESET);
	return (tmp);
}
