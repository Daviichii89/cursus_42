/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:01:51 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 22:24:17 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int  init_philo_mutexes(t_philo *philo)
{
    if (pthread_mutex_init(&philo->death_check, NULL))
        return (1);
    if (pthread_mutex_init(&philo->status_mtx, NULL))
    {
        pthread_mutex_destroy(&philo->death_check);
        return (1);
    }
    return (0);
}

static int  init_philos(t_data *data)
{
    int i;
    
    data->philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
    if (!data->philos)
        return (1);
    i = -1;
    while (++i < data->n_philos)
    {
        data->philos[i].id = i;
        data->philos[i].last_meal = 0;
        data->philos[i].meal_count = 0;
        data->philos[i].status = WAITING_SIMULATION;
        data->philos[i].simu_on = true;
        data->philos[i].print_mtx = &data->print_mtx;
        data->philos[i].first_fork = data->forks + i;
        data->philos[i].data = data;
        if (data->n_philos == i + 1)
            data->philos[i].second_fork = data->forks;
        else
            data->philos[i].second_fork = data->forks + i + 1;
        if (init_philo_mutexes(&data->philos[i]))
            return (free_philos(data, i));
    }
    return (0);
}

int    init_data(t_data *data)
{
    if (init_forks(data->n_philos, &data->forks) == -1)
        return (1);
    if (pthread_mutex_init(&data->print_mtx, NULL)
        || init_philos(data) == -1)
    {
        free_forks(&data->forks, data->n_philos);
        pthread_mutex_destroy(&data->print_mtx);
        return(1);
    }
    return (0);
}
