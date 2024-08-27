/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:00:29 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/26 18:38:00 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	ft_atol(char *str)
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

static long	check_int_range(t_data *data, char *argv)
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

int	check_arg(char **argv, t_data **data)
{
	(*data)->n_philos = check_int_range(*data, argv[1]);
	if ((*data)->n_philos < 1)
		return (1);
	(*data)->time_to_die = check_int_range(*data, argv[2]) * 1000;
	(*data)->time_to_eat = check_int_range(*data, argv[3]) * 1000;
	(*data)->time_to_sleep = check_int_range(*data, argv[4]) * 1000;
	if (argv[5])
		(*data)->n_meals = check_int_range(*data, argv[5]);
	else
		(*data)->n_meals = -1;
	return (0);
}
