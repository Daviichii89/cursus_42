/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:12 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/20 15:20:37 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)p1;
	str2 = (unsigned char *)p2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char *str1 = "abcdfe";
	char *str2 = "abcdje";
	int n = 5;
	int result = ft_memcmp(str1, str2, n);
	int result2 = memcmp(str1, str2, n);
	printf("%d\n", result);
	printf("%d\n", result2);
	return (0);
}*/
