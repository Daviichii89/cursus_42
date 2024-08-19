/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/06/04 13:57:45 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

static int	print_error(int return_value, char *str_error)
{
	printf("%s\n", str_error);
	return (return_value);
}

int create_threads(t_data *data)
{
    static int  i;
    static int  j;
    pthread_t   *threads;

    i = 0;
    threads = malloc(sizeof(pthread_t) * data->n_philos);
    if (!threads)
        return (1);
    pthread_mutex_init(&data->lfork, NULL);
    pthread_mutex_init(&data->rfork, NULL);
    while (i < data->n_philos)
    {
        if (pthread_create(&threads[i], NULL, routine, (void *)&data[i]))
            return (-1);
        i++;
    }
    j = 0;
    while (i < data->n_philos)
    {
        if (pthread_join(threads[j], NULL))
            return (-1);
        j++;
    }
    pthread_mutex_destroy(&data->lfork);
    pthread_mutex_destroy(&data->rfork);
    return (0);
}

void    start_simulation(t_data *data)
{
    if (data->n_philos == 1)
    {
        long    current_time;

    current_time = data->simu_start.tv_sec * 1000 + data->simu_start.tv_usec / 1000;
        printf("%ld Philosopher %d has taken left fork\n", current_time, data->n_philos);
        usleep(data->time_to_die * 1000);
        printf("%ld Philosopher 1 died\n", current_time);
        return ;
    }
    else
    {
        if (create_threads(data) == -1)
            return ;
    }
}

int check_arg(char **argv, t_data **data)
{
    int             philo_n;
    struct  timeval start;

    philo_n = ft_atoi(argv[1]);
    *data = malloc(sizeof(t_data) * philo_n);
    if (!(*data))
        return (1);
    (*data)->n_philos = philo_n;
    (*data)->time_to_die = ft_atoi(argv[2]);
    (*data)->time_to_eat = ft_atoi(argv[3]);
    (*data)->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        (*data)->philo_eats = ft_atoi(argv[5]);
    else
        (*data)->philo_eats = -1;
    gettimeofday(&start, NULL);
    (*data)->simu_start = start;
    return (0);
}

int main(int argc, char **argv)
{
    t_data  *data;

    data = NULL;
    if (argc != 5 && argc != 6)
	{
        print_error(1, "Error: wrong number of arguments\n");
		return (1);
	}
    if (check_arg(argv, &data))
        return (1);
    start_simulation(data);
	free (data);
    return (0);
}
