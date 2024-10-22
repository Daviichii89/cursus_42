/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 20:26:35 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool is_philo_dead(t_philo *philo, long simu_start)
{
	long	elapsed_time;
	long	timestamp;

	if (philo->status == FULL)
		return (false);
	timestamp = get_timestamp(simu_start);
	elapsed_time = timestamp - philo->last_meal;
	if (elapsed_time > philo->data->time_to_die)
		return (true);
	return (false);
}

static void	check_philos(t_data *data)
{
	long	i;
	long	philo_full;

	i = -1;
	philo_full = 0;
	while (philo_full != data->n_philos && !data->simu_end)
	{
		if (++i == data->n_philos)
		{
			i = 0;
			philo_full = 0;
		}
		if (pthread_mutex_lock(&data->philos[i].death_check))
			return ;
		if (is_philo_dead(&data->philos[i], data->simu_start))
			data->simu_end = true;
		else if (data->philos[i].status == FULL)
			philo_full++;
		if (pthread_mutex_unlock(&data->philos[i].death_check))
			return ;
	}
	if (data->simu_end)
		update_print_status(DEAD, &data->philos[i]);
}

void	start_simulation(t_data *data)
{
	long	i;

	data->simu_start = get_time();
	data->simu_end = false;
	i = -1;
	while (++i < data->n_philos)
		pthread_create(&data->philos[i].philo_thread, NULL, routine, &data->philos[i]);
	check_philos(data);
	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philos[i].philo_thread, NULL);
	
	
}

