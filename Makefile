# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 13:06:50 by davifer2          #+#    #+#              #
#    Updated: 2024/01/10 13:01:06 by davifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_memchr: ft_memchr.c ft_strlen.c
	cc -o test2 ft_memchr.c ft_strlen.c
	./test2
isalpha: ft_isalpha.c
	cc -o test3 ft_isalpha.c
	./test3
bzero: ft_bzero.c ft_memset.c
	cc -o test4 ft_bzero.c ft_memset.c
