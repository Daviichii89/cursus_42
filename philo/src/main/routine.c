/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/02 20:21:14 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

// void	philo_sleeping(t_data *data)
// {
// 	printf("Philosopher %d is sleeping\n", data->philos->philo_id);
// 	usleep(data->time_to_sleep);
// }

// void	philo_eating(t_data *data)
// {
// 	t_philo	*philo;

// 	philo = data->philos;
// 	pthread_mutex_lock(&philo->left_fork->fork_mutex);
// 	printf("Philosopher %d has taken a fork\n", philo->philo_id);
// 	pthread_mutex_lock(&philo->right_fork->fork_mutex);
// 	printf("Philosopher %d has taken a fork\n", philo->philo_id);
// 	philo->meal_count++;
// 	printf("Philosopher %d is eating\n", philo->philo_id);
// 	usleep(data->time_to_eat);
// 	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
// 	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
// }

// void	*routine(void *arg)
// {
// 	t_data	*data;
// 	int		id;

// 	data = (t_data *)arg;
// 	id = data->philos->philo_id;
// 	if (data->n_philos <= 0)
// 		return (NULL);
// 	philo_eating(data);
// 	philo_sleeping(data);
// 	printf("Philosopher %d is thinking\n", id);
// 	return (NULL);
// }
