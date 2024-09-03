/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 21:15:53 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

void	philo_sleeping(t_philo *philo)
{
	printf("Philosopher %d is sleeping\n", philo->philo_id);
	usleep(philo->time_to_sleep);
}

void	philo_eating(t_philo *philo)
{
	t_fork *first_fork;
	t_fork *second_fork;

	if (philo->philo_id % 2 == 0)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	if (pthread_mutex_lock(first_fork))
		return ;
	printf("Philosopher %d has taken left fork\n", philo->philo_id);
	if (pthread_mutex_lock(second_fork))
		return ;
	printf("Philosopher %d has taken right fork\n", philo->philo_id);
	philo->meal_count++;
	printf("Philosopher %d is eating\n", philo->philo_id);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}

void	*routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	while (!philo.data->dead && !philo.data->simu_end)
	{
		philo_eating(&philo);
		philo_sleeping(&philo);
		printf("Philosopher %d is thinking\n", philo.philo_id);
	}
	return (NULL);
}
