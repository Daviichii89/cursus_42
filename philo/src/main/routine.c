/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/06/04 15:15:42 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

void    philo_sleeping(t_data *data)
{
    long    current_time;

    current_time = data->simu_start.tv_sec * 1000 + data->simu_start.tv_usec / 1000;
    printf("%li Philosopher %d is sleeping\n", current_time, data->philo_id);
    usleep(data->time_to_sleep * 1000);
}

void    philo_eating(t_data *data)
{
    long    current_time;

    current_time = data->simu_start.tv_sec * 1000 + data->simu_start.tv_usec / 1000;
    pthread_mutex_lock(&data->lfork);
    pthread_mutex_lock(&data->rfork);
    printf("%ld Philosopher %d has taken left fork\n", current_time, data->philo_id);
    printf("%ld Philosopher %d has taken right fork\n", current_time, data->philo_id);
    printf("%ld Philosopher %d is eating\n", current_time, data->philo_id);
    usleep(data->time_to_eat * 1000);
    pthread_mutex_unlock(&data->lfork);
    pthread_mutex_unlock(&data->rfork);
}

void    *routine(void *arg)
{
    t_data	*philo;
    static int  i;

    philo = (t_data *)arg;
    i = 0;
    while (++i < philo->n_philos)
        philo->philo_id = i;
    philo_eating(philo);
    philo_sleeping(philo);
    return (NULL);
}