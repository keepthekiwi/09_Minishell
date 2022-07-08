/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:14:59 by skillian          #+#    #+#             */
/*   Updated: 2022/07/06 18:49:29 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../includes/minishell.h"

# define PRINT_ENV			2
# define GET_ENV			3
# define TOKEN				4
# define ENV				5

typedef struct s_token		t_token;
typedef struct s_minishell	t_minishell;

typedef struct s_env /* wenn hier was geander, auch ft_feel_free_env aendern */
{
	char			*name;
	char			*content;
	bool			hidden;
	struct s_env	*next;
}	t_env;

typedef struct s_export
{
	int		i;
	int		j;
	char	*var;
}			t_export;

int		ft_echo(t_token *ptr_list);
void	echo_errorcode_cmd_printer(char *str);
void	norminette_is_your_friend(char *str);
t_env	*ft_getenv(char *name, t_env *env_list);
char	*malloc_env_content(char *env_content);
void	ft_env_fetch_origin(t_minishell *minishell, char **envp);
char	*get_data_for_env_node(char *datapoint);
char	*fetch_env_data(char *datapoint);
int		*create_env_node_add_to_list(t_minishell *minishell, \
		char *datapoint, bool hide);
void	ft_lstadd_back_i_env(t_minishell *minishell, t_env *new);
char	**t_env_in_arr_convert(t_minishell *list, int i);
char	*remove_quotes(char *str);
int		ft_export(t_token *token, t_minishell *minishell);
t_env	*search_in_env_list(t_env *node, char *input);
bool	is_upper_str(char *str);
bool	char_checker(char *check, char c);
int		ft_cd(t_token *input, t_minishell *minishell);
bool	check_access(char *direction);
void	env_printer(t_minishell *minishell);
int		ft_unset(t_token *token, t_env *list);
void	get_it_out_of_list(t_env **list, t_env *found);
t_env	*find_node_before(t_env *list, t_env *found);
int		ft_pwd(void);
void	handle_cmd_signals(void);
void	handle_global_signals(void);
void	sigfunc_child(int sig); /* handle signal in the child process */
void	free_env_list(t_minishell *minishell);
void	free_token_list(t_minishell *minishell);
void	feel_free_node_env(t_env *node);
void	feel_free_node_token(t_token *token);
int		export_cmd_printer(t_minishell *minishell);
int		check_if_valid_identifier(char *str);
bool	echo_n_option_checker(char *str);
bool	secret_easter_egg(char *str);
bool	unset_validity_checker(char *str);
void	digit_not_valid_printer(char *str);
void	test(t_token *token, t_export *exp);
void	create_new_env(t_minishell *minishell, t_env *tmp_env, t_export *exp);
char	*add_words(t_token **token);

#endif