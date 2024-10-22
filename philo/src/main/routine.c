/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 23:12:00 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	leave_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(get_second_fork(philo)))
		return (1);
	if (pthread_mutex_unlock(get_first_fork(philo)))
		return (1);
	return (0);
}

static int	pickup_forks(t_philo *philo)
{
	if (pthread_mutex_lock(get_first_fork(philo)))
		return (1);
	update_print_status(PICKUP_FORK, philo);
	if (get_first_fork(philo) == get_second_fork(philo)
		|| pthread_mutex_unlock(get_second_fork(philo)))
	{
		pthread_mutex_unlock(get_first_fork(philo));
		return (1);
	}
	update_print_status(PICKUP_FORK, philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->meal_count == philo->data->n_meals)
		update_status(philo, FULL);
	if (philo->id % 2 != 0 && !check_status(philo, FULL))
	{
		update_print_status(THINKING, philo);
		ft_usleep(philo->data->time_to_eat / 2);
	}
	while (philo->simu_on && !check_status(philo, FULL))
	{
		if (pickup_forks(philo))
			break ;
		update_print_status(EATING, philo);
		if(philo->simu_on)
			ft_usleep(philo->data->time_to_eat);
		if (leave_forks(philo))
			break ;
		update_print_status(SLEEPING, philo);
		if (philo->simu_on)
			ft_usleep(philo->data->time_to_sleep);
		update_print_status(THINKING, philo);
	}
	return (NULL);
}
