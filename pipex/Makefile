# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:29:19 by davifer2          #+#    #+#              #
#    Updated: 2024/08/23 16:58:08 by davifer2         ###   ########.fr        #
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

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -Iinc/ -Ilibft/inc/

NAME = pipex

# Librerias
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
LIB_FLAGS = -lft -Llibft -lreadline
##

SRC_PATH = src/
OBJS_PATH = objects/
DEPS_PATH = deps/

SRCS = main/pipex.c \


OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS = ${addprefix $(DEPS_PATH), $(SRCS:.c=.d)}

all: libftmake $(NAME)

libftmake: $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) --no-print-directory

$(NAME):  $(OBJS) inc/minishell.h $(LIBFT_PATH)inc/libft.h $(LIBFT_PATH)libft.a Makefile
	@echo "\n"
	@echo "$(YELLOW)Compiling pipex...\n"
	@echo "$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)
	@echo "$(GREEN)\n"
	@echo "	===================	"
	@echo "	 pipex created	"
	@echo "	===================	"
	@echo "\n"
	@echo "$(DEF_COLOR)"


$(OBJS_PATH)%.o: $(SRC_PATH)%.c inc/pipex.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@mkdir -p $(subst $(OBJS_PATH),$(DEPS_PATH),$(@D))
	@mv $(patsubst %.o,%.d,$@) $(subst $(OBJS_PATH),$(DEPS_PATH),$(@D))/

clean:
	@if [ -d "$(OBJS_PATH)" ] && [ -n "$$(find $(OBJS_PATH) -name '*.o' -print -quit)" ]; then \
		echo "\n"; \
		echo "$(YELLOW)Removing object files...$(RED)"; \
		make -C $(LIBFT_PATH) clean > /dev/null; \
		rm -rf $(OBJS_PATH) $(DEPS_PATH); \
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
		echo "$(DEF_COLOR)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ] || [ -d "$(LIBFT_PATH)" ] && [ -n "$$(find $(LIBFT_PATH) -name '*.a' -print -quit)" ]; then \
		echo "\n"; \
		echo "$(YELLOW)Removing all files...$(RED)"; \
		make -C $(LIBFT_PATH) fclean > /dev/null; \
		rm -rf $(NAME); \
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
		echo "$(DEF_COLOR)"; \
	fi

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re
