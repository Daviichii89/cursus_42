/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:10:00 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/09 16:25:22 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

char	*ft_strnstr(char *str, char *to_find, size_t max_length)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
int main() {
    const char *haystack = "Hola, esto es una cadena de prueba.";
    const char *needle = "es";
    size_t max_length = 20;

    // Busca la subcadena "es" en la cadena de prueba con un límite de 20 caracteres.
    char *result = ft_strnstr(haystack, needle, max_length);

    if (result != NULL) {
        printf("Subcadena encontrada en la posición: %ld\n", result - haystack);
    } else {
        printf("Subcadena no encontrada.\n");
    }

    return 0;
}
