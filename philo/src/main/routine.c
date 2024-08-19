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
    // long    current_time;

    // current_time = data->simu_start.tv_sec * 1000 + data->simu_start.tv_usec / 1000;
    printf("Philosopher %d is sleeping\n", data->philo_id);
    usleep(data->time_to_sleep * 1000);
}

void    philo_eating(t_data *data)
{
    if (data->n_philos <= 0)
    {
        printf("Error inside philo_eating: number of philosophers must be greater than 0\n");
        return ;
    }
    int left_fork = data->philo_id;
    int right_fork = (data->philo_id + 1) % data->n_philos;
    pthread_mutex_lock(&data->forks[left_fork]);
    pthread_mutex_lock(&data->forks[right_fork]);
    printf("Philosopher %d has taken left fork\n", data->philo_id);
    printf("Philosopher %d has taken right fork\n", data->philo_id);
    printf("Philosopher %d is eating\n", data->philo_id);
    usleep(data->time_to_eat * 1000);
    pthread_mutex_unlock(&data->forks[left_fork]);
    pthread_mutex_unlock(&data->forks[right_fork]);
}

void *routine(void *arg) {
    t_data *data = (t_data *)arg; 
    int id = data->philo_id;

    if (data->n_philos <= 0) {
        printf("Error inside routine: number of philosophers must be greater than 0 in routine\n");
        return NULL;
    }
    printf("Philosopher %d is thinking\n", id);
    philo_eating(data);
    philo_sleeping(data);

    return NULL;
}