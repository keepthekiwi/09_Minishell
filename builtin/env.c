/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:14:19 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 15:04:16 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h" // andere Lib

char	**get_env_names(char **environ)
{
	int		i;
	char	**arr;
	char	*tmp_pos;

	i = 0;
	while (environ[i])
		i++;
	arr = ft_calloc(sizeof(char *), i + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		arr[i] = ft_strdup(environ[i]);
		tmp_pos = ft_strchr(arr[i++], '=');
		tmp_pos[0] = '\0';
	}
	return (arr);
}

void	ft_env_fetch_origin(t_minishell *minishell, char **envp)
{
	char	*datapoint;
	int		i;
	char	**arr;

	arr = get_env_names(envp);
	i = 0;
	while (arr[i])
	{
		datapoint = arr[i];
		create_env_node_add_to_list(minishell, datapoint, false);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	env_printer(t_minishell *minishell)
{
	t_env	*env_lst;

	env_lst = minishell->env_list;
	while (env_lst)
	{
		if (env_lst->hidden == false)
			printf("%s=%s\n", env_lst->name, env_lst->content);
		env_lst = env_lst->next;
	}
}

char	**t_env_in_arr_convert(t_minishell *list, int i)
{
	char	**arr;
	t_env	*env_token;
	t_env	*tmp;
	char	*tmp_str;

	env_token = NULL;
	tmp = list->env_list;
	if (!env_token)
		return (0);
	while (tmp && i++)
		tmp = tmp->next;
	arr = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (env_token)
	{
		if (env_token->hidden == false)
		{
			tmp_str = ft_strjoin("=", env_token->content);
			arr[i] = ft_strjoin(env_token->name, tmp_str);
			free(tmp_str);
		}
		i++;
		env_token = env_token->next;
	}
	return (arr);
}
