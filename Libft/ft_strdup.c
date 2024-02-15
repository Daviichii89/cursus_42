/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:58 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/22 02:50:28 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strdup(const char *src)
{
	char *str;
	int i;
	int size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (0);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}
/*
int main(void)
{
	char *src;

	src = NULL;
	//char *result = ft_strdup(src);
	char *result = strdup(src);
	printf("%s", result);
}
*/