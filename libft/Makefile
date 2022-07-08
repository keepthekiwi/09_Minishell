# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skillian <skillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 17:30:56 by nhaas             #+#    #+#              #
#    Updated: 2022/05/10 14:29:37 by skillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



INCLUDES = libft.h
NAME = libft.a
SOURCES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c \
			ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_lstnew.c ft_strrchr.c \
	  		ft_lstadd_front.c \
	  		ft_lstsize.c \
	  		ft_lstlast.c \
	  		ft_lstadd_back.c \
	  		ft_lstdelone.c \
	  		ft_lstclear.c \
	  		ft_lstiter.c \
	  		ft_lstmap.c \
			ft_strcmp.c
			
OBJECTS = $(SOURCES:%.c=%.o)
all: $(NAME)
bonus: all
$(NAME): $(OBJECTS)
	@ar rcs $@ $(OBJECTS)
%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@
clean:
	@rm -f $(OBJECTS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
