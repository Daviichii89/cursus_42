# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:31:27 by davifer2          #+#    #+#              #
#    Updated: 2024/01/31 19:16:36 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = #-Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJECTS)
	make -C libft
	ar rcs $(NAME) $(OBJECTS)
%.o: %.c Makefile libft.h
	cc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)
	make -C libft fclean
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
