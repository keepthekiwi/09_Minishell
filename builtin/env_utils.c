/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:46:55 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:47:14 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_getenv(char *name, t_env *env_list)
{
	t_env	*tmp;

	tmp = env_list;
	if (tmp == NULL || name == NULL)
		return (NULL);
	if (ft_strcmp(name, "?") == 0)
		return (NULL);
	while (tmp)
	{
		if (tmp->name == NULL)
			return (NULL);
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_lstadd_back_i_env(t_minishell *minishell, t_env *new)
{
	t_env	*tmp_env;

	if (new == NULL)
		return ;
	if (minishell->env_list == NULL)
		minishell->env_list = new;
	else
	{
		tmp_env = minishell->env_list;
		while (tmp_env && tmp_env->next != NULL)
			tmp_env = tmp_env->next;
		tmp_env->next = new;
		new->next = NULL;
	}
}

char	*malloc_env_content(char *env_content)
{
	char	*content;
	int		len;

	if (env_content == NULL)
		return (NULL);
	len = ft_strlen(env_content);
	content = malloc(sizeof(char) * (len + 1));
	if (!content)
		return (NULL);
	content = ft_strlcpy_r(content, env_content, (len + 1));
	return (content);
}

char	*get_data_for_env_node(char *datapoint)
{
	char	*env_content;
	char	*tmp_env_content;

	env_content = getenv(datapoint);
	tmp_env_content = malloc_env_content(env_content);
	return (tmp_env_content);
}

int	*create_env_node_add_to_list(t_minishell *minishell,
		char *datapoint, bool hide)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->name = ft_strdup(datapoint);
	if (!hide)
		env->content = get_data_for_env_node(datapoint);
	else
		env->content = NULL;
	env->hidden = hide;
	env->next = NULL;
	ft_lstadd_back_i_env(minishell, env);
	return (0);
}
