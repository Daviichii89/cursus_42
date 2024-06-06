# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 12:40:29 by davifer2          #+#    #+#              #
#    Updated: 2024/06/04 14:05:50 by davifer2         ###   ########.fr        #
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

NAME = philo

OBJS_PATH = objects/

SOURCES = src/philosophers.c \

OBJECTS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SOURCES))
DEPS = $(SOURCES:.c=.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -pthread

all: $(NAME)


$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) -o $@
	@echo "$(GREEN)\n"
	@echo "	=================	"
	@echo "	 philo created	"
	@echo "	=================	"
	@echo "\n"

$(OBJS_PATH)%.o: %.c Makefile philosophers.h
	@echo "$(YELLOW)Compiling philo...\n"
	@mkdir -p $(OBJS_PATH) 
	@$(CC) $(CFLAGS) -c $< -o $@

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
