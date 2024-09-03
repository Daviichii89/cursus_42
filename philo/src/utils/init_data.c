/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:01:51 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 21:17:15 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_forks(int n_philos, t_fork **forks)
{
    t_fork    *fork;
    int i;

    i = 0;
    fork = malloc(sizeof(t_fork) * n_philos);
    if (!fork)
        return (1);
    while (i < n_philos)
    {
        if (pthread_mutex_init(fork + i, NULL))
            break ;
        i++;
    }
    *forks = fork;
    return (0);
}

int init_philos(t_data *data, char **args)
{
    int		i;
	
	i = 0;
    data->philo = malloc(sizeof(t_philo) * data->n_philos);
    if (!data->philo)
        return (1);
    while (i < data->n_philos)
	{
        data->philo[i].philo_id = i + 1;
        data->philo[i].time_to_die = ft_atol(args[2]);
        data->philo[i].time_to_eat = ft_atol(args[3]);
        data->philo[i].time_to_sleep = ft_atol(args[4]);
        data->philo[i].meal_count = 0;
        data->philo[i].left_fork = data->forks + i;
        data->philo[i].right_fork = &data->forks[(i + 1) % data->n_philos];
        data->philo[i].data = data;
		i++;
	}
    print_data(&data);
    return (0);
}

int init_data(t_data **data, char **args, int total_args)
{
    *data = malloc(sizeof(t_data));
    if (!(*data))
    {
        printf("Error: malloc failed\n");
        return (1);
    }
    (*data)->n_philos = ft_atol(args[1]);
    if (total_args == 6)
        (*data)->n_meals = ft_atol(args[5]);
    else
        (*data)->n_meals = -1;
    (*data)->dead = 0;
    if ((*data)->n_philos < 1 || (*data)->n_philos > 200)
    {
        printf("Error: wrong input format\n");
        return (1);
    }
    if (init_forks((*data)->n_philos, &(*data)->forks))
        return (1);
    if (init_philos(*data, args))
        return (1);
    return (0);
}
