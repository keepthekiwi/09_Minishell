/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:32:40 by skillian          #+#    #+#             */
/*   Updated: 2022/07/07 16:27:12 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <sys/stat.h> 
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <termios.h>
# include "../builtin/builtin.h"

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define BLUE2		"\033[0;36m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define RESET		"\x1B[0m"

typedef struct s_env	t_env;
int						g_error_code;

typedef enum s_rd_type
{
	RD_STDOUT,
	RD_STDIN,
	DRD_STDOUT,
	NONE
}	t_rd_type;

typedef enum s_type
{
	NOTSET,
	PIPE,
	SREDIRECTION,
	DREDIRECTION,
	CMD,
	BUILTIN,
	OPTION,
	ARG,
	DQUOTE,
	SQUOTE,
	ABSPATH,
	RELPATH,
	HOMEPATH,
}	t_type;

struct s_expander
{
	int		i;
	int		j;
	int		len_env_var;
	char	*tmp_str;
	char	*env_var;
	char	*tmp_env_var;
	int		len;
	t_env	*tmp;
};

typedef struct s_token
{
	char			*str;
	char			*path;
	char			**cmd_str;
	struct s_token	*before;
	struct s_token	*next;
	bool			space;
	t_type			type;
	t_rd_type		rd_type;
}	t_token;

// not in use
typedef struct s_cmd
{
	char			*whole_cmd;
	t_type			type;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_minishell
{
	t_cmd	*cmds;
	t_token	*pre_parsed;
	t_token	*current_token;
	char	*path;
	char	*promt;
	char	*user;
	char	*home_path;
	bool	valid_cmd;
	int		pre_parsed_len;
	int		i_cmds;
	int		i_pipes;
	int		fd[2];
	int		tmp_fd;
	int		std_in;
	int		std_out;
	int		rd_fd;
	char	**env_arr;
	t_env	*env_list;
}	t_minishell;

void		expander(t_minishell *minishell);
void		print_pre_parsed_lst(t_token *token);
void		print_token(t_token *token);
char		*get_promt(t_minishell *minishell, char **envp);
int			handle_input(t_minishell *minishell, char *input);
void		parser(t_minishell *minishell);
void		print_cmds_lst(t_cmd *cmd);
int			lexer(char *pos, t_minishell *minishell);
void		free_pre_parsed(t_minishell *minishell);
void		lst_converter_pipe(t_minishell *minishell, t_token *token);
void		lst_converter(t_minishell *minishell);
char		*extract_word_and_add_token(t_minishell *minishell, \
			char *pos, bool space, bool quotes);
int			*create_token_and_add_to_list(t_minishell *minishell, \
			char *word, bool space);
bool		is_white_space_or_quote(char *to_check);
char		*ignore_white_space(char *pos);
void		tester_print_list(t_token *node);
t_token		*ft_lstlast_t_node(t_token *lst);
char		*ft_strlcpy_r(char *dest, const char *src, size_t size);
void		ft_lstadd_back_i(t_token *lst, t_token *new);
char		*create_word(char *pos, char *start);
bool		empty_word_checker(char *word);
bool		operator_checker(char *pos);
bool		double_operator_checker(char *pos);
char		*pos_second_quote(char *pos);
char		*get_bin_path(t_minishell *minishell, t_token *tmp_token);
t_token		*get_cmd_token(t_minishell *minishell);
int			check_i_pipes_token(t_minishell *minishell);
int			setup_pipe(t_minishell *minishell, t_token *tmp_token);
t_type		check_type_till_pipe(t_minishell *minishell);
int			check_i_pipes_token(t_minishell *minishell);
int			is_there_rd(t_token *rd_token);
t_token		*get_redirection(t_minishell *minishell);
char		*get_pwd(t_minishell *minishell);
t_rd_type	check_rd_type(t_token *tmp_token);
int			execute_without_pipes(t_minishell *minishell);
void		execute_with_pipes(t_minishell *minishell);
void		execute_builtin(char *str, t_token *token, t_minishell *minishell);
void		execute_cmd(t_minishell *minishell);
t_token		*get_cmd_token(t_minishell *minishell);
int			ret_perror(char *str, int err);
int			equal_quotes_checker(char *input_str, int i);
void		executer(t_minishell *minishell, char *input);
int			handle_stdin_rd(t_minishell *minishell);
int			handle_stdout_rd(t_minishell *minishell);
void		handle_redirections(t_minishell *minishell);
int			check_i_pipes_token(t_minishell *minishell);
void		count_cmds(t_minishell *minishell);
void		handle_multi_stdout_rd(t_minishell *minishell);
int			is_there_rd(t_token *rd_token);
int			handle_stdout_rd_without_pipes(t_minishell *minishell);
int			handle_stdin_rd_without_pipes(t_minishell *minishell);
void		exit_minishell(t_minishell *minishell);
char		*search_env_path(char **paths, char *str);
void		set_cmd_path(t_minishell *minishell);
int			set_type(t_minishell *minishell, t_token *token);
void		init_vars(struct s_expander *vars);
int			insert_env_var(t_token *token, t_minishell *minishell, int pos);
bool		check_is_cmd(t_minishell *minishell, t_token *token);
bool		check_is_buildin(char *str);
void		type_handling(t_minishell *minishell);
int			check_type_order_sub1(t_token *tmp_token);
void		handle_stdout_rd_stdout(t_minishell *minishell);
int			handle_stdin_rd_without_pipes_pipe(t_minishell *minishell,
				t_token *tmp_token, int test_fd);
bool		check_is_cmd(t_minishell *minishell, t_token *token);
int			check_type_order_sub1(t_token *tmp_token);
t_env		*ft_getenv(char *name, t_env *env_list);
char		*remove_quotes_new(char *str);
void		check_identifier(char *str);
t_type		get_type(char chr, t_type type);
char		*add_words(t_token **token);
int			free_expander_vars(struct s_expander vars);
char		*free_char_ret(char *free_str);

#endif
