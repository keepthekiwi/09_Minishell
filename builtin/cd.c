/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:12:33 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 14:38:14 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	ft_cd(t_token *input, t_minishell *minishell)
{
	t_env	*env;
	char	cwd[PATH_MAX];
	char	*direction;

	if (!input)
	{
		if (!ft_getenv("HOME", minishell->env_list))
			return (printf(" cd: HOME not set"));
		direction = (ft_getenv("HOME", minishell->env_list))->content;
	}
	else
		direction = input->str;
	if (direction == NULL || !check_access(direction))
		return (0);
	if (chdir(direction))
		return (errno);
	env = ft_getenv("PWD", minishell->env_list);
	if (!env)
		return (0);
	if (!getcwd(cwd, sizeof(cwd)))
		return (errno);
	free(env->content);
	env->content = ft_strdup(cwd);
	return (0);
}

bool	check_access(char *direction)
{
	int	access_result;

	access_result = access(direction, F_OK);
	if (access_result == -1)
	{
		printf("minishell: cd: No such file or directory\n");
		g_error_code = 1;
		return (false);
	}
	return (true);
}
