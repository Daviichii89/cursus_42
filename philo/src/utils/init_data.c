/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:01:51 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/09 22:08:01 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void    assign_forks(t_philo *philo, t_mtx *forks, int philo_pos)
{
    int n_philos;

    n_philos = philo->data->n_philos;
    philo->first_fork = &forks[philo_pos];
    philo->second_fork = &forks[(philo_pos + 1) % n_philos];
}

static int  init_philo(t_data *data)
{
    int i;


    data->philos = (t_philo*)malloc(sizeof(t_philo) * data->n_philos);
    if (!data->philos)
        return (error_msg("malloc philos failed\n"));
    i = -1;
    while (++i < data->n_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].full = false;
        data->philos[i].meal_count = 0;
        data->philos[i].last_meal = 0;
        data->philos[i].data = data;
        assign_forks(&data->philos[i], data->forks, i);
    }
    return (0);
}

int    init_data(t_data *data)
{
    int i;

    i = -1;
    data->simu_end = false;
    data->forks = (t_mtx *)malloc(sizeof(t_mtx) * data->n_philos);
    if (!data->forks)
        return (error_msg("malloc forks failed\n"));
    while (++i < data->n_philos)
        pthread_mutex_init(&data->forks[i], NULL);

    if(init_philo(data))
        return (1);
    print_data(&data);
    return (0);
}
