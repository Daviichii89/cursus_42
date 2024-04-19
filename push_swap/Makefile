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

NAME = push_swap

SRCS = 			push_swap.c

SRCS_UTILS = 	utils/create_stack.c utils/ft_atol.c utils/ft_lstclear.c \
				utils/ft_lstlast.c utils/ft_lstsize.c \
				utils/init_nodes_a.c utils/init_nodes_b.c \
				utils/ft_split.c utils/is_sorted.c

SRCS_ALGO =		algorithms/sort_3.c algorithms/algorithms_utils.c \
				algorithms/sort.c

SRCS_ACTIONS =  actions/swap_command.c actions/push_command.c \
				actions/rotate_command.c actions/reverse_rotate_command.c

OBJS = $(SRCS:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)
OBJS_ALGO = $(SRCS_ALGO:.c=.o)
OBJS_ACTIONS = $(SRCS_ACTIONS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_UTILS) $(OBJS_ALGO) $(OBJS_ACTIONS)
	@echo "$(YELLOW)Compiling ft_printf...$(GREEN)"
	@make -C printf
	@echo "$(YELLOW)Compiling push swap...$(GREEN)"
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) $(OBJS_ALGO) $(OBJS_ACTIONS) printf/libftprintf.a -o $(NAME)
	@echo "\n"
	@echo "	===================	"
	@echo "	 push swap created	"
	@echo "	===================	"
	@echo "\n"

%.o: %.c Makefile push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n"
	@echo "$(YELLOW)Removing object files...$(RED)"
	@$(RM) $(OBJS) $(OBJS_UTILS) $(OBJS_ALGO) $(OBJS_ACTIONS)
	@make -C printf clean
	@echo "\n"
	@echo "	======================	"
	@echo "	 All .o files removed	"
	@echo "	======================	"
	@echo "\n"

fclean: clean
	@echo "\n"
	@echo "$(YELLOW)Removing all files...$(RED)"
	@$(RM) $(NAME)
	@make -C printf fclean
	@echo "\n"
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re
