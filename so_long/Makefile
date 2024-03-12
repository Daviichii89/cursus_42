# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:29:19 by davifer2          #+#    #+#              #
#    Updated: 2024/03/12 16:32:12 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = main.c so_long.c

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

OBJECTS = $(SOURCES:.c=.o)

all: makemlx $(NAME)
$(NAME): $(OBJ)
    $(CC) $(OBJ) $(MLX) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
makemlx:
	make -C mlx/
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
