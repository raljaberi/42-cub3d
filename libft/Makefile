# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 19:29:23 by raljaber          #+#    #+#              #
#    Updated: 2025/01/12 11:06:16 by raljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = \
	ft_isdigit.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_split.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c
	
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs  $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
