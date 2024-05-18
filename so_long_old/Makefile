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

SOURCES = so_long.c read_map.c get_next_line.c get_next_line_utils.c ft_free.c \
			ft_error.c ft_bzero.c ft_calloc.c ft_memset.c print_map.c \
			check_exit.c

MLX = -L. -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c Makefile so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C mlx/ -s
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 mlx created	"
	@echo "	==============	"
	@echo "\n"
	@cp mlx/libmlx.a .
	@$(CC) $(OBJECTS) $(MLX) -o $(NAME)
	@echo "\n"
	@echo "	===================	"
	@echo "	 so_long created	"
	@echo "	===================	"
	@echo "\n"

clean:
	@echo "\n"
	@echo "$(YELLOW)Removing object files...$(RED)"
	@make -C mlx/ clean
	@rm -f $(OBJECTS)
	@echo "\n"
	@echo "	======================	"
	@echo "	 All .o files removed	"
	@echo "	======================	"
	@echo "\n"

fclean: clean
	@echo "\n"
	@echo "$(YELLOW)Removing all files...$(RED)"
	@make -C mlx/ clean
	@rm -f $(NAME)
	@rm -f libmlx.a
	@echo "\n"
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re
