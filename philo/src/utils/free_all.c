/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 20:05:53 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    free_forks(t_mutex **forks, int n_forks)
{
    int i;

    i = -1;
    while (++i != n_forks)
        pthread_mutex_destroy(&forks[i]);
    free(*forks);
    *forks = NULL;
}

int free_philos(t_data *data, long n_philos)
{
    long    i;

    i = -1;
    while (++i < n_philos)
    {
        if (pthread_mutex_destroy(&data->philos[n_philos].death_check) == -1)
            break ;
        if (pthread_mutex_destroy(&data->philos[n_philos].status_mtx) == -1)
            break ;
    }
    free(data->philos);
    return (-1);
}
