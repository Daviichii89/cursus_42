/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:32:07 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/19 15:06:32 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	str = (char *) malloc(len);
	ft_strlcpy(str, (char *)s1, i + 1);
	ft_strlcat(&str[i], (char *)s2, j + 1);
	return (str);
}

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*result;

	str1 = "Hola ";
	str2 = "mundo";
	result = ft_strjoin(str1, str2);
	printf("El resultado es: %s", result);
	return (0);
}
