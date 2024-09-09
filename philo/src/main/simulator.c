/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/09 22:13:12 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//  

long	get_time(t_time_code time_code)
{
	struct timeval	time;

	
	if (gettimeofday(&time, NULL))
		return (error_msg("Error getting time\n"));
	if (time_code == SECOND)
		return (time.tv_sec + time.tv_usec / 1000000);
	else if (time_code == MILLISECOND)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	else if (time_code == MICROSECOND)
		return ((time.tv_sec * 1000000) + time.tv_usec);
	return (error_msg("Invalid time code\n"));
}

void	ft_usleep(long milliseconds)
{
	long	start_time;

	start_time = get_time(MILLISECOND);
	while ((get_time(MILLISECOND) - start_time) < milliseconds)
		usleep(milliseconds / 2);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = -1;
	data->simu_start = get_time(MILLISECOND);
	if (!data->n_meals)
		return ;
	// else if (data->n_philos == 1)
	// {
	// 	printf("%.10ld Philosopher %d has taken the first fork\n", get_time(MILLISECOND), data->philos[0].id);
	// 	ft_usleep(data->time_to_die);
	// 	printf("%.10ld Philosopher %d died\n", get_time(MILLISECOND), data->philos[0].id);
	// 	return ;
	// }
	while (++i < data->n_philos)
		if (pthread_create(&data->philos[i].philo_thread, NULL, routine,
				&data->philos[i]))
			return ;
	// revisar si llega a comer antes de que muera
	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philos[i].philo_thread, NULL);
}

