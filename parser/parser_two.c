/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:29:30 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:29:43 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	check_is_buildin(char *str)
{
	if (!str)
		return (NULL);
	if (ft_strncmp(str, "echo", 5) == 0)
		return (true);
	else if (ft_strncmp(str, "cd", 3) == 0)
		return (true);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (true);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (true);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (true);
	else
		return (false);
}

char	*search_env_path(char **paths, char *str)
{
	int		i;
	char	*tmp_abs_path;
	char	*third_tmp;

	i = 0;
	while (paths[i] != NULL)
	{
		tmp_abs_path = ft_strjoin(paths[i], "/");
		if (tmp_abs_path == NULL)
			return (NULL);
		third_tmp = ft_strjoin(tmp_abs_path, str);
		free(tmp_abs_path);
		if (third_tmp == NULL)
			return (NULL);
		tmp_abs_path = third_tmp;
		if (access(tmp_abs_path, F_OK) == 0)
			return (tmp_abs_path);
		free(tmp_abs_path);
		i++;
	}
	return (NULL);
}

bool	check_is_cmd(t_minishell *minishell, t_token *token)
{
	char	*tmp_str;

	tmp_str = get_bin_path(minishell, token);
	if (tmp_str)
	{
		free(tmp_str);
		return (true);
	}
	else
	{
		free(tmp_str);
		return (false);
	}
}
