/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:53:29 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/20 15:13:00 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len_nbr(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_fill_str(int nbr, int len, char *result)
{
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10 ;
	}
	return (result);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*result;

	len = ft_len_nbr(nbr);
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	result = ft_fill_str(nbr, len, result);
	return (result);
}
/*
	int main(void)
	{
		char *result1 = ft_itoa(12345);
		char *result2 = ft_itoa(-456);
		char *result3 = ft_itoa(0);
		char *result4 = ft_itoa(10);
		char *result5 = ft_itoa(2147483647);
		char *result6 = ft_itoa(-2147483648);

		printf("El resultado de 12345 es: %s\n", result1);
		printf("El resultado de -456 es: %s\n", result2);
		printf("El resultado de 0 es: %s\n", result3);
		printf("El resultado de 10 es: %s\n", result4);
		printf("El resultado de 2147483647 es: %s\n", result5);
		printf("El resultado de -2147483648 es: %s\n", result6);
		return (0);
	}
*/
