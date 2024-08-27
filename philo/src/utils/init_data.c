/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:01:51 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/26 18:38:29 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->n_philos);
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i].fork_mutex, NULL);
		data->forks[i].fork_id = i;
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		philos->philo_id = i + 1;
		philos->meal_count = 0;
		philos->max_meals = data->n_meals;
		philos->data = data;
		pthread_mutex_init(&philos->philo_mutex, NULL);
		i++;
	}
}
