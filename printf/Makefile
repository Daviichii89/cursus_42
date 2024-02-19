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
LIBFT = ./libft/libft.a
CFLAGS = #-Wall -Werror -Wextra

all: $(NAME) $(LIBFT)
$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $(NAME) $(OBJECTS)
%.o: %.c Makefile ft_printf.h
	cc $(CFLAGS) -c $< -o $@
$(LIBFT):
	make -C ./libft all
clean:
	rm -f $(OBJECTS)
	make -C ./libft clean
fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
re: fclean all
.PHONY: all clean fclean re
