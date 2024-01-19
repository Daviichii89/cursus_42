/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:39:52 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/19 16:44:38 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	printf("El valor de j: %d\n", j);
	while (i < j && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (j > i && ft_strchr(set, s1[j]))
	{
		j--;
	}
	str = ft_substr(s1, i, j + 1);
	if (!(str))
		return (0);
	return (str);
}
/*
int	main(void)
{
	char		str[] = "  uu  Houla uu   ";
	const char	*set = " u";
	char		*result = ft_strtrim(str, set);
	printf("%s", result);
	return (0);
}
*/
