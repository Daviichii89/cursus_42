/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/09 21:29:20 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

void	philo_sleeping(t_philo *philo)
{
	printf("%.10ld Philosopher %d is sleeping\n",(get_time(MILLISECOND) - philo->data->simu_start), philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	// printf("%.10ld Philosopher %d has taken the first fork\n", (get_time(MILLISECOND) - philo->data->simu_start), philo->id);
	pthread_mutex_lock(philo->second_fork);
	// printf("%.10ld Philosopher %d has taken the second fork\n", (get_time(MILLISECOND) - philo->data->simu_start), philo->id);
	philo->meal_count++;
	printf("%.10ld Philosopher %d is eating\n", (get_time(MILLISECOND) - philo->data->simu_start), philo->id);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	if (philo->data->n_meals && philo->meal_count == philo->data->n_meals)
		printf("%.10ld Philosopher %d is full\n", (get_time(MILLISECOND) - philo->data->simu_start), philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->simu_end)
	{
		philo_eating(philo);
		// philo_sleeping(philo);
		if (philo->data->n_meals && philo->meal_count == philo->data->n_meals)
		{
			philo->full = true;
			philo->data->simu_end = true;
			break ;
		}
		// printf("%.10ld Philosopher %d is thinking\n",(get_time(MILLISECOND) - philo->data->simu_start), philo->id);
	}
	return (NULL);
}
