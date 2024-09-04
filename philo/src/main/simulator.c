/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/04 23:44:40 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(t_time_code time_code)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (error_msg("Error getting time\n"));
	if (time_code == SECOND)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	else if (time_code == MILLISECOND)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (time_code == MICROSECOND)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	return (error_msg("Invalid time code\n"));
}

void	start_simulation(t_data *data)
{
	int	i;

	i = -1;
	if (!data->n_meals)
		return ;
	else if (data->n_philos == 1)
	{
		printf("%ld %d has taken the first fork\n", get_time(MILLISECOND), data->philos[0].id);
		usleep(data->time_to_die);
		printf("%ld %d died\n", get_time(MILLISECOND), data->philos[0].id);
		return ;
	}
	else
	{
		while (++i < data->n_philos)
			pthread_create(&data->philos[i].philo_thread, NULL, routine,
				&data->philos[i]);
	}
	data->simu_start = get_time(MILLISECOND);
	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philos[i].philo_thread, NULL);
}

