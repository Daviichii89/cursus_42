# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:29:19 by davifer2          #+#    #+#              #
#    Updated: 2024/03/12 16:32:12 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME = so_long

SOURCES = so_long.c \
		  gnl/get_next_line.c gnl/get_next_line_utils.c \
		  utils/ft_free.c utils/ft_error.c utils/ft_bzero.c \
		  utils/ft_calloc.c utils/ft_memset.c \
		  checks/print_map.c checks/check_exit.c checks/read_map.c

MLX = -L. -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@echo "Compiling $@"
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C mlx/
	@echo "Compilated mlx"
	@cp mlx/libmlx.a .
	@$(CC) $(OBJECTS) $(MLX) -o $(NAME)
	@echo "Compilated so_long"

clean:
	@echo "Cleaning..."
	@make -C mlx/ clean
	@rm -f $(OBJECTS)
	@echo "Cleaned objects successfully"

fclean: clean
	@echo "Full cleaning"
	@make -C mlx/ clean
	@rm -f $(NAME)
	@rm -f libmlx.a
	@echo "Cleaned all objects and executables successfully"

re: fclean all

.PHONY: all clean fclean re
