# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:29:19 by davifer2          #+#    #+#              #
#    Updated: 2024/05/29 19:35:26 by davifer2         ###   ########.fr        #
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

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft/
LIBFT = -Llibft -l ftprintf

SOURCES = so_long.c so_long_utils.c \
		  init_sprites.c check_map.c render_map.c moves.c

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD

all: $(NAME)


$(NAME): $(OBJECTS) Makefile so_long.h libft/Makefile
	@echo "$(YELLOW)Compiling libft...\n"
	@make -C $(LIBFT_PATH)
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 libft created	"
	@echo "	==============	"
	@echo "\n"

	@echo "$(YELLOW)Compiling mlx...\n"
	@make -C mlx/ 2> /dev/null
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 mlx created	"
	@echo "	==============	"
	@echo "\n"

	@echo "$(YELLOW)Compiling so_long...\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) -o $@
	@echo "$(GREEN)\n"
	@echo "	===================	"
	@echo "	 so_long created	"
	@echo "	===================	"
	@echo "\n"

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -I libft/inc -c $< -o $@

clean:
	@echo "\n"
	@echo "$(YELLOW)Removing object files...$(RED)"
	@make -C $(LIBFT_PATH) clean
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
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "\n"
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re
