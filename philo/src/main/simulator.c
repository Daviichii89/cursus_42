/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/02 20:21:34 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	start_simulation(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	if (data->n_meals == 0)
// 		return ;
// 	else if (data->n_philos == 1)
// 	{
// 		printf("1 1 has taken a fork\n");
// 		usleep(data->time_to_die);
// 		printf("1 1 died\n");
// 		return ;
// 	}
// 	else
// 	{
// 		while (i < data->n_philos)
// 		{
// 			pthread_create(&data->philos[i].philo_thread, NULL, routine,
// 				&data->philos[i]);
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (i < data->n_philos)
// 	{
// 		pthread_join(data->philos[i].philo_thread, NULL);
// 		i++;
// 	}
// }
