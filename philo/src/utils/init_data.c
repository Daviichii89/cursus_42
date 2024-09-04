/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:01:51 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/04 23:05:08 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void    assign_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
    int n_philos;

    n_philos = philo->data->n_philos;
    philo->first_fork = &forks[(philo_pos + 1) % n_philos];
    philo->second_fork = &forks[philo_pos];
    if (philo->id % 2 == 0)
    {
        philo->first_fork = &forks[philo_pos];
        philo->second_fork = &forks[(philo_pos + 1) % n_philos];
    }
}

static void    init_philo(t_data *data)
{
    int i;
    t_philo *philo;

    i = -1;
    while (++i < data->n_philos)
    {
        philo = data->philos + i;
        philo->id = i + 1;
        philo->full = false;
        philo->meal_count = 0;
        philo->data = data;
        assign_forks(philo, data->forks, i);
    }
}

int    init_data(t_data *data)
{
    int i;

    i = -1;
    data->simu_end = false;
    data->all_ready = false;
    data->philos = malloc(sizeof(t_philo) * data->n_philos);
    if (!data->philos)
        return (error_msg("malloc failed\n"));
    pthread_mutex_init(&data->data_mtx, NULL);
    data->forks = malloc(sizeof(t_fork) * data->n_philos);
    if (!data->forks)
        return (error_msg("malloc failed\n"));
    while (++i < data->n_philos)
    {
        pthread_mutex_init(&data->forks[i].fork, NULL);
        data->forks[i].id = i;
    }
    init_philo(data);
    print_data(&data);
    return (0);
}
