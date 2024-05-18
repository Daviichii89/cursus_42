# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 13:06:50 by davifer2          #+#    #+#              #
#    Updated: 2024/01/22 17:35:42 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Iinc
CFLAGS = -Wall -Werror -Wextra

GNL_DIR = src/gnl
PRINTF_DIR = src/printf

SOURCES_LIBFT = src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_itoa.c \
	src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c \
	src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c \
	src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putstr_fd.c \
	src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c \
	src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c src/ft_strncmp.c \
	src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c src/ft_substr.c \
	src/ft_tolower.c src/ft_toupper.c \
	src/ft_lstnew_bonus.c src/ft_lstsize_bonus.c src/ft_lstadd_back_bonus.c \
	src/ft_lstadd_front_bonus.c	src/ft_lstlast_bonus.c \
	src/ft_lstdelone_bonus.c src/ft_lstclear_bonus.c src/ft_lstiter_bonus.c \
	src/ft_lstmap_bonus.c

SOURCES_GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SOURCES_PRINTF = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_hexlen.c \
	$(PRINTF_DIR)/ft_nbrlen.c $(PRINTF_DIR)/ft_nbrunsiglen.c \
	$(PRINTF_DIR)/ft_printchar_fd.c $(PRINTF_DIR)/ft_printhex_fd.c \
	$(PRINTF_DIR)/ft_printnbr_fd.c $(PRINTF_DIR)/ft_printnbrunsig_fd.c \
	$(PRINTF_DIR)/ft_printstr_fd.c

SOURCES = $(SOURCES_LIBFT) $(SOURCES_GNL) $(SOURCES_PRINTF)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) Makefile inc/libft.h inc/ft_printf.h inc/get_next_line.h
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
