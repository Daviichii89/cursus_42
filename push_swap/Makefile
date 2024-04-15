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
	@echo "Compiling ft_printf..."
	@make -C printf
	@echo "Compiling push swap..."
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
	@echo "Removing object files..."
	@$(RM) $(OBJS) $(OBJS_UTILS) $(OBJS_ALGO) $(OBJS_ACTIONS)
	@make -C printf clean
	@echo "\n"
	@echo "	======================	"
	@echo "	 All .o files removed	"
	@echo "	======================	"
	@echo "\n"

fclean: clean
	@echo "\n"
	@echo "Removing all files..."
	@$(RM) $(NAME)
	@make -C printf fclean
	@echo "\n"
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re
