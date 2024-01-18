/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:32:07 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/18 16:39:28 by davifer2         ###   ########.fr       */
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

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(len * sizeof(char));
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[j + i] = s2[j];
		j++;
	}
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
