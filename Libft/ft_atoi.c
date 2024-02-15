/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:34:26 by davifer2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/09 11:38:55 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_atoi(char *str)
{
	int	sign;
	int	res;
=======
/*   Updated: 2024/01/20 15:06:54 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;
>>>>>>> master

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
<<<<<<< HEAD
			sign -= 1;
=======
			sign = -1;
>>>>>>> master
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}
<<<<<<< HEAD
=======
/*
int	main(void)
{
	const	char *str = "2147483649";
	int	result = ft_atoi(str);
	int	result2 = atoi(str);
	printf("ft_atoi: %d\n", result);
	printf("atoi: %d", result2);
}*/
>>>>>>> master
