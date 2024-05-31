# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:29:19 by davifer2          #+#    #+#              #
#    Updated: 2024/05/31 14:02:15 by davifer2         ###   ########.fr        #
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
LIB_NAME = libft/libftprintf.a
MLX_NAME = mlx/libmlx.a

LIBFT_PATH = libft/
OBJS_PATH = objects/

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = -Llibft -l ftprintf

SOURCES = so_long.c so_long_utils.c \
		  init_sprites.c check_map.c render_map.c moves.c

OBJECTS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SOURCES))
DEPS = $(SOURCES:.c=.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD

all: $(NAME)


$(NAME): $(OBJECTS) libfta $(MLX_NAME)
	@echo "$(YELLOW)Compiling so_long...\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) -o $@
	@echo "$(GREEN)\n"
	@echo "	===================	"
	@echo "	 so_long created	"
	@echo "	===================	"
	@echo "\n"

$(OBJS_PATH)%.o: %.c Makefile so_long.h
	@mkdir -p $(OBJS_PATH) 
	@$(CC) $(CFLAGS) -Ilibft/inc -c $< -o $@

libfta: libft/Makefile	
	@echo "$(YELLOW)Compiling libft...\n"
	@make -C $(LIBFT_PATH) --no-print-directory
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 libft created	"
	@echo "	==============	"
	@echo "\n"

$(MLX_NAME): mlx/Makefile
	@echo "$(YELLOW)Compiling mlx...\n"
	@make -C mlx/ &> /dev/null
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 mlx created	"
	@echo "	==============	"
	@echo "\n"

clean:
	@if [ -d "$(OBJS_PATH)" ] && [ -n "$$(find $(OBJS_PATH) -name '*.o' -print -quit)" ]; then \
		echo "\n"; \
		echo "$(YELLOW)Removing object files...$(RED)"; \
		make -C $(LIBFT_PATH) clean > /dev/null; \
		make -C mlx/ clean > /dev/null; \
		rm -rf $(OBJS_PATH); \
		rm -f $(OBJECTS); \
		echo "\n"; \
		echo "	======================	"; \
		echo "	 All .o files removed	"; \
		echo "	======================	"; \
		echo "\n"; \
	else \
		echo "$(RED)\n"; \
		echo "	========================	"; \
		echo "	 No .o files to remove.	"; \
		echo "	========================	"; \
		echo "\n"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ] || [ -d "$(LIBFT_PATH)" ] && [ -n "$$(find $(LIBFT_PATH) -name '*.a' -print -quit)" ]; then \
		echo "\n"; \
		echo "$(YELLOW)Removing all files...$(RED)"; \
		make -C $(LIBFT_PATH) fclean > /dev/null; \
		rm -f $(NAME); \
		echo "\n"; \
		echo "	===================	"; \
		echo "	 All files removed	"; \
		echo "	===================	"; \
		echo "\n"; \
	else \
		echo "$(RED)\n"; \
		echo "	=====================	"; \
		echo "	 No files to remove.	"; \
		echo "	=====================	"; \
		echo "\n"; \
	fi
-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re
