CLIENT_NAME = client
CLIENT_BONUS_NAME = client_bonus
SERVER_NAME = server
SERVER_BONUS_NAME = server_bonus

CLIENT_SRCS = client.c ft_atoi.c
CLIENT_BONUS_SRCS = client_bonus.c ft_atoi.c
SERVER_SRCS = server.c
SERVER_BONUS_SRCS = server_bonus.c

OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)
OBJS_CLIENT_BONUS = $(CLIENT_BONUS_SRCS:.c=.o)
OBJS_SERVER = $(SERVER_SRCS:.c=.o)
OBJS_SERVER_BONUS = $(SERVER_BONUS_SRCS:.c=.o)

PRINTF = printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)



bonus: $(PRINTF) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@echo "Compiling bonus..."
	@$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(PRINTF) -o $(SERVER_BONUS_NAME)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(PRINTF) -o $(CLIENT_BONUS_NAME)
	@echo "\n"
	@echo "	===============	"
	@echo "	 bonus created	"
	@echo "	===============	"
	@echo "\n"

$(CLIENT_NAME): $(PRINTF) $(OBJS_CLIENT)
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(CLIENT_NAME)
	@echo "\n"
	@echo "	================	"
	@echo "	 client created	"
	@echo "	================	"
	@echo "\n"

$(SERVER_NAME): $(PRINTF) $(OBJS_SERVER)
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(SERVER_NAME)
	@echo "\n"
	@echo "	================	"
	@echo "	 server created	"
	@echo "	================	"
	@echo "\n"

$(PRINTF):
	@echo "Compiling libftprintf.a..."
	@make -C printf
	@echo "\n"
	@echo "	=======================	"
	@echo "	 libftprintf.a created	"
	@echo "	=======================	"
	@echo "\n"

%.o: %.c Makefile minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@make -C printf clean
	@echo "	======================	"
	@echo "	 All .o files removed	"
	@echo "	======================	"
	@echo "\n"

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)
	@make -C printf fclean
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

re: fclean all

.PHONY: all bonus clean fclean re
