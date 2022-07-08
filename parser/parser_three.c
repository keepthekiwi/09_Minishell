/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:28:11 by nhaas             #+#    #+#             */
/*   Updated: 2022/07/06 18:30:47 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	type_handling(t_minishell *minishell)
{
	t_token	*tmp_token;

	tmp_token = minishell->pre_parsed;
	while (tmp_token != NULL)
	{
		if (set_type(minishell, tmp_token) != 0)
			printf("%s\n", "error setting type");
		minishell->pre_parsed_len++;
		tmp_token = tmp_token->next;
	}
	set_cmd_path(minishell);
}

t_cmd	*new_cmd(char *str)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->next = NULL;
	cmd->type = NOTSET;
	if (str != NULL)
		cmd->whole_cmd = str;
	else
		cmd->whole_cmd = NULL;
	return (cmd);
}

static void	ft_free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted && splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

char	*get_bin_path(t_minishell *minishell, t_token *tmp_token)
{
	char	**paths;
	char	*tmp_abs_path;
	t_env	*tmp_env;

	if (access(tmp_token->str, F_OK) == 0)
		return (ft_strdup(tmp_token->str));
	tmp_env = minishell->env_list;
	while (tmp_env && ft_strncmp(tmp_env->name, "PATH", 5) != 0)
		tmp_env = tmp_env->next;
	if (tmp_env == NULL)
		return (NULL);
	paths = ft_split(tmp_env->content, ':');
	if (paths == NULL)
	{
		ft_free_split(paths);
		return (NULL);
	}
	tmp_abs_path = search_env_path(paths, tmp_token->str);
	ft_free_split(paths);
	return (tmp_abs_path);
}

int	check_type_order_sub1(t_token *tmp_token)
{
	if (tmp_token->type == OPTION && tmp_token->before->type != BUILTIN
		&& tmp_token->before->type != CMD && (tmp_token->type != OPTION
			&& ft_strcmp(tmp_token->before->str, "echo") == 0))
		return (ret_perror("parsing", 2));
	if (tmp_token->type == PIPE && (tmp_token->before->type == SREDIRECTION
			|| tmp_token->before->type == DREDIRECTION
			|| tmp_token->str[1] != '\0'))
		return (ret_perror("parsing", 2));
	if ((tmp_token->type == PIPE || tmp_token->type == SREDIRECTION
			|| tmp_token->type == DREDIRECTION) && tmp_token->next == NULL)
		return (ret_perror("parsing", 2));
	return (0);
}
