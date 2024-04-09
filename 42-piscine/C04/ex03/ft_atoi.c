/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:49:01 by davifer2          #+#    #+#             */
/*   Updated: 2023/12/14 18:20:47 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	digit;
	int	sign;

	i = 0;
	digit = 0;
	sign = 1;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '+' || (str[i] >= 8 && str[i] <= 13))
		{
		}
		else if (str[i] == '-')
			sign *= -1;
		else
			return (digit);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = digit * 10 + (str[i] - '0');
		i++;
	}
	digit *= sign;
	return (digit);
}
/*
int	main(void)
{
	int result = ft_atoi("-");
	printf("%d\n", result);
	return (0);
}*/
