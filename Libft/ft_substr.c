/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:27 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/18 16:23:42 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;

	substring = (char *)malloc(len * sizeof(char));
	i = start;
	while (i < len)
	{
		substring[i] = s[i];
		i++;
	}
	substring[i] = '\0';
	return (&substring[start]);
}

int	main(void)
{
	char	*str;
	char	*result;

	str = "Hola mundo";
	result = ft_substr(str, 5, 10);
	printf("El resultado es: %s", result);
	return (0);
}
