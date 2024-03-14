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

SOURCES = main.c so_long.c

MLX = -L. -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra

%.o: %.c
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
all: $(NAME)
$(NAME): $(OBJECTS)
	@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
	@make -C mlx/
	@cp mlx/libmlx.a .
	@$(CC) $(SOURCES) $(MLX) -o $(NAME)
	@echo "$(GREEN)Created ${NAME} ✓$(DEF_COLOR)\n"
clean:
	@make -C mlx/ clean
	@rm -f $(OBJECTS)
	@echo "${RED}All objects cleaned successfully✓$(DEF_COLOR)\n"
fclean: clean
	@make -C mlx/ clean
	@rm -f $(OBJECTS)
	@echo "${RED}All objects and executable cleaned successfully✓$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
