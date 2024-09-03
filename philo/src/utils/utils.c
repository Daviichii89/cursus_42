/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:27:37 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/02 20:22:53 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	check_int_range(t_data *data, char *argv)
{
	long	input;

	(void) data;
	input = ft_atol(argv);
	if (input > INT_MAX)
	{
		error_msg(2, "Input Error: The value cannot exceed 2147483647");
		return (1);
	}
	if (input < 1)
	{
		error_msg(2, "Input Error: Positive values only");
		return (1);
	}
	return (input);
}

long	ft_atol(char *str)
{
	long		res;

	res = 0;
	if (!str)
	{
		error_msg(2, "Wrong input format");
		return (0);
	}
	while ((*str == '+' || *str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-')
		return (0);
	if (!(*str >= '0' && *str <= '9'))
	{
		error_msg(2, "Wrong input format");
		return (0);
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int    ft_strlen(char *str)
{
    int	i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}