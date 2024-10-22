/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:00:29 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 19:48:29 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(t_data *data ,char **args)
{
	data->n_philos = ft_atol(args[1]);
	data->time_to_die = ft_atol(args[2]);
	data->time_to_eat = ft_atol(args[3]);
	data->time_to_sleep = ft_atol(args[4]);
	if (data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60 || data->n_philos < 1)
		return(error_msg("Values must be greater than 60"));
	if (args[5])
	{
		data->n_meals = ft_atol(args[5]);
		if (data->n_meals < 1)
			return(error_msg("Number of meals must be greater than 0"));
	}
	else
		data->n_meals = -1;
	return (0);
}
