# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:29:19 by davifer2          #+#    #+#              #
#    Updated: 2024/03/12 16:06:44 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = so_long.c read_map.c get_next_line.c get_next_line_utils.c ft_free.c \
			ft_error.c ft_bzero.c ft_calloc.c ft_memset.c print_map.c \
			check_exit.c

MLX = -L. -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@echo "Compiling $@"
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C mlx/
	@echo "Compilated mlx"
	@cp mlx/libmlx.a .
	@$(CC) $(OBJECTS) $(MLX) -o $(NAME)
	@echo "Compilated so_long"

clean:
	@echo "Cleaning..."
	@make -C mlx/ clean
	@rm -f $(OBJECTS)
	@echo "Cleaned objects successfully"

fclean: clean
	@echo "Full cleaning"
	@make -C mlx/ clean
	@rm -f $(NAME)
	@rm -f libmlx.a
	@echo "Cleaned all objects and executables successfully"

re: fclean all

.PHONY: all clean fclean re