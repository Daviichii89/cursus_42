/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:08:54 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 22:19:19 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_mutex	*get_first_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (philo->first_fork);
	return (philo->second_fork);
}

t_mutex	*get_second_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (philo->second_fork);
	return (philo->first_fork);
}

int	init_forks(int total_forks, t_mutex **forks)
{
	int	i;

	*forks = (t_mutex *)malloc(sizeof(t_mutex) * total_forks);
	if (!(*forks))
		return (1);
	i = -1;
	while (++i < total_forks)
		if (pthread_mutex_init((*forks) + i, NULL))
			break ;
	if (i != total_forks)
	{
		printf(RED"Error creating forks\n"RST);
		free_forks(forks, i);
		return (-1);
	}
	return (0);
}