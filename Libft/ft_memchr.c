/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:48:29 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/20 15:17:18 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (0);
}
/*
int main() {
	const char *str = "Hello, World!";
	char searchChar = 'o';

	// Buscar la primera aparición de 'W' en la cadena
	const char *result = (const char *)ft_memchr(str,
		searchChar, ft_strlen(str));

	if (result != NULL) {
		printf("Encontrado '%c' en la posición %ld.\n",
		searchChar, result - str);
	} else {
		printf("'%c' no encontrado en la cadena.\n", searchChar);
	}

	return 0;
}*/
