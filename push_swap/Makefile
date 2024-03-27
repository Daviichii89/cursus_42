NAME = push_swap

SRCS = push_swap.c 
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n"
	@echo "	===================	"
	@echo "	 Push Swap created	"
	@echo "	===================	"
	@echo "\n"

%.o: %.c Makefile push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n"
	@echo "Removing object files..."
	@rm -f $(OBJS)
	@echo "\n"
	@echo "	======================	"
	@echo "	 All .o files removed	"
	@echo "	======================	"
	@echo "\n"

fclean: clean
	@echo "\n"
	@echo "Removing all files..."
	@rm -f $(NAME)
	@echo "\n"
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re
