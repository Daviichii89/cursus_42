CLIENT_NAME = client
CLIENT_BONUS_NAME = client_bonus
SERVER_NAME = server
SERVER_BONUS_NAME = server_bonus

CLIENT_SRCS = client.c ft_atoi.c
CLIENT_BONUS_SRCS = client_bonus.c ft_atoi_bonus.c
SERVER_SRCS = server.c
SERVER_BONUS_SRCS = server_bonus.c

OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)
OBJS_CLIENT_BONUS = $(CLIENT_BONUS_SRCS:.c=.o)
OBJS_SERVER = $(SERVER_SRCS:.c=.o)
OBJS_SERVER_BONUS = $(SERVER_BONUS_SRCS:.c=.o)

PRINTF = printf/libftprintf.a
PRINTF_BONUS = printf_bonus/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME) 

$(CLIENT_BONUS_NAME): $(PRINTF_BONUS) $(OBJS_CLIENT_BONUS)
	@echo "Compiling client bonus..."
	@$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(PRINTF_BONUS) -o $(CLIENT_BONUS_NAME)
	@echo "\n"
	@echo "	====================== 	"
	@echo "	 client bonus created	"
	@echo "	======================	"
	@echo "\n"

$(SERVER_BONUS_NAME): $(PRINTF_BONUS) $(OBJS_SERVER_BONUS)
	@echo "Compiling server bonus..."
	@$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(PRINTF_BONUS) -o $(SERVER_BONUS_NAME)
	@echo "\n"
	@echo "	======================  "
	@echo "	 server bonus created   "
	@echo "	======================  "
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
	@make -C printf_bonus
	@echo "\n"
	@echo "	=======================	"
	@echo "	 libftprintf.a created	"
	@echo "	=======================	"
	@echo "\n"

$(PRINTF_BONUS):
	@echo "Compiling libftprintf.a..."
	@make -C printf_bonus
	@echo "\n"
	@echo " ======================= "
	@echo "  libftprintf.a created  "
	@echo " ======================= "
	@echo "\n"

%.o: %.c Makefile minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@make -C printf clean
	@make -C printf_bonus clean
	@echo "	======================	"
	@echo "	 All .o files removed	"
	@echo "	======================	"
	@echo "\n"

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)
	@make -C printf fclean
	@make -C printf_bonus fclean
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n"

re: fclean all

.PHONY: all bonus clean fclean re
