/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:02:23 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/10 17:58:54 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <string.h>
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	unsigned char *str1;
	unsigned char *str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	printf("str1: %c y str2: %c\n",str1[i], str2[i]);
	return (str1[i] - str2[i]);
}

int main()
{
	char *str1 = "abcd\0";
	char *str2 = "abcd\200";
	int n = 4;
	int result = ft_strncmp(str1, str2, n);
	int result2 = strncmp(str1, str2, n);
	printf("%d\n", result);
	printf("%d\n", result2);
	return (0);
}
