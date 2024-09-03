/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 20:09:31 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_data *data)
{
	int	i;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return ;
	i = -1;
	data->simu_start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	printf("Current time: %ld\n", data->simu_start);
	while (++i < data->n_philos)
		pthread_create(&data->philo[i].philo_thread, NULL, routine,
			&data->philo[i]);
	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philo[i].philo_thread, NULL);
}
