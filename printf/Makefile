# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:31:27 by davifer2          #+#    #+#              #
#    Updated: 2024/02/22 15:02:46 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c \
		  ft_putnbr_fd.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_strlen.c \
		  ft_nbrlen.c

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
%.o: %.c Makefile ft_printf.h
	cc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
