/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 20:55:53 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->meal_count == philo->data->n_meals)
		update_status(philo, FULL);
	if (philo->id % 2 != 0 && !check_status(philo, FULL))
	{
		update_and_print_status(THINKING, philo);
		usleep(100);
	}
	while (!philo->data->simu_end)
	{
		philo_eating(philo);
		philo_sleeping(philo);
		printf("%.10ld Philosopher %d is thinking\n",(philo->data->simu_start - get_time(MILLISECOND)), philo->id);
	}
	return (NULL);
}
