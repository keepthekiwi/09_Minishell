

CC = gcc

LDFLAGS= -L/Users/$(USER)/.brew/opt/readline/lib -lreadline

CFLAGS = -Wall -Wextra -g -c -I/Users/$(USER)/.brew/opt/readline/include -Iincludes -Werror

LIBFT = libft/libft.a

INCLUDES = minishell.h
NAME = minishell

SRC_DIR = src
SRC_FILES =		main.c \
				m_utils.c \
				expander/expander.c \
				expander/expander_utils.c \
				prompt/prompt.c \
				expander/handle_input.c \
				parser/parser.c \
				parser/parser_utils.c \
				parser/parser_two.c \
				parser/parser_three.c \
				lexer/lexer.c \
				lexer/utils_one.c \
				lexer/utils_two.c \
				builtin/echo.c \
				builtin/echo_utils.c \
				builtin/env.c \
				builtin/env_utils.c \
				builtin/export.c \
				builtin/export_utils.c \
				builtin/unset.c \
				builtin/unset_utils.c \
				builtin/cd.c \
				builtin/pwd.c \
				builtin/signals.c \
				helper/free.c \
				redirection.c \
				redirection_helper.c \
				redirection_two.c \
				redirection_three.c \
				executer.c \
				execute_without_pipes.c \
				execute_with_pipes.c \
				helper_pipe.c \

T_OBJ = $(SRC_FILES:c=o)

LIB_DIR = includes/
LIB_FILES = minishell.h

OBJ_DIR = output/
OBJ = $(addprefix $(OBJ_DIR), $(T_OBJ))

# ------------------------------ Colors --------------------------------

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
GREEN		=	\033[32m
NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

START			=	echo "\n🚧 $(BOLD_YELLOW)Make:	$(NO_COLOR)Starting the compilation..."
LIBFT_READY		=	echo "✅ $(GREEN)READY:	$(NO_COLOR)libft"
READY			=	echo "✅ $(GREEN)READY:	$(NO_COLOR)minishell\n"
CLEANED			=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files"
FCLEANED		=	echo "🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables\n"

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ) $(SA_PATH) $(LIB_PATH)
	@$(START)
	@$(LIBFT_READY)
	@$(CC) -o $@ $(OBJ) -Llibft -lft ./libft/libft.a $(LDFLAGS)
	@$(READY)

$(OBJ_DIR):
	mkdir $(OBJ_DIR) $(OBJ_DIR)expander $(OBJ_DIR)builtin $(OBJ_DIR)lexer $(OBJ_DIR)parser $(OBJ_DIR)prompt $(OBJ_DIR)helper

$(OBJ_DIR)%.o: %.c $(LIB_DIR)$(LIB_FILES)
	@$(CC) $(CFLAGS) $< -o $@

$(READLINE_PATH):
	sh ./install_readline.sh

$(LIBFT):
	make -C libft

all: $(NAME)

bonus: all

clean:
	@rm -rf $(OBJ_DIR)
	@$(CLEANED)

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@$(FCLEANED)

readline: $(READLINE_PATH)

re: fclean all


# @mv *.o $(OBJ_DIR)