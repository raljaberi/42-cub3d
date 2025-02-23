# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 11:49:47 by raljaber          #+#    #+#              #
#    Updated: 2025/02/03 12:51:03 by raljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = base.c \
		check.c \
		colors.c \
		main.c \
		draw.c \
		error.c \
		init.c \
		texture.c \
		keys.c \
		parsing.c \
		raycast.c \
		map.c \
		extra.c

GNLSRCS = ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME) : $(OBJS)
	make all -sC minilibx
	make all -sC libft
	$(CC) $(CFLAGS) $(OBJS) $(GNLSRCS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	make clean -sC minilibx
	make clean -sC libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -sC libft
	rm -f $(NAME)

re: fclean all