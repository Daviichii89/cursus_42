/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:27:48 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/09 17:35:18 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	int	i;

	i = 0;
	p = s;
	printf("%s\n", p);
	while (i < n)
	{
		printf("En el bucle soy: %d\n", *p);
		if (*p == (unsigned char)c)
		{
			printf("%c\n", *p);
			return ((void *)p);
		}
		i++;
		p++;
	}
	return (0);
}
int main() {
    const char *str = "Hello, World!";
    char searchChar = 'W';

    // Buscar la primera aparición de 'W' en la cadena
    const char *result = (const char *)ft_memchr(str, searchChar, strlen(str));

    if (result != NULL) {
        printf("Encontrado '%c' en la posición %ld.\n", searchChar, result - str);
    } else {
        printf("'%c' no encontrado en la cadena.\n", searchChar);
    }

    return 0;
}
