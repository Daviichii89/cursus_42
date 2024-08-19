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
    int         i;
    pthread_t   *threads;

    printf("Creating threads\n");
    threads = malloc(sizeof(pthread_t) * data->n_philos);
    if (!threads)
        return (1);

    // Inicializamos los mutexes
    data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
    if (!data->forks)
    {
        free(threads);
        return (1);
    }
    for (i = 0; i < data->n_philos; i++)
        pthread_mutex_init(&data->forks[i], NULL);

    // Creación de los hilos de los filósofos
    for (i = 0; i < data->n_philos; i++)
    {
        data[i].philo_id = i; // Asignar el ID correcto al filósofo
        data->meals = 0; // Inicializar el contador de comidas
        if (pthread_create(&threads[i], NULL, routine, (void *)&data[i]))
        {
            printf("Error: thread creation failed\n");
            free(threads);
            return (-1);
        }
        printf("Thread %d created\n", i);
    }

    // Esperar a que los hilos terminen
    for (i = 0; i < data->n_philos; i++)
    {
        if (pthread_join(threads[i], NULL))
            return (-1);
    }

    // Destruir los mutexes
    for (i = 0; i < data->n_philos; i++)
        pthread_mutex_destroy(&data->forks[i]);

    free(threads);
    free(data->forks);
    return (0);
}

void    start_simulation(t_data *data)
{
    if (data->n_philos == 1)
    {
        // long    current_time;

        // current_time = data->simu_start.tv_sec * 1000 + data->simu_start.tv_usec / 1000;
        printf("Philosopher %d has taken left fork\n", data->n_philos);
        usleep(data->time_to_die * 1000);
        printf("Philosopher 1 died\n");
        return ;
    }
    else
    {
        int tmp = create_threads(data);
        if (tmp == -1)
        {
            printf("Error: threads creation failed\n");
            return ;
        }
        printf("tmp: %d\n", tmp);
        printf("Threads created\n");
    }
}

void    print_data(t_data *data)
{
    printf("====================================\n");
    printf("Number of philosophers: %d\n", data->n_philos);
    printf("Time to die: %d\n", data->time_to_die);
    printf("Time to eat: %d\n", data->time_to_eat);
    printf("Time to sleep: %d\n", data->time_to_sleep);
    printf("Philo eats: %d\n", data->philo_eats);
    printf("Simu start: %ld\n", data->simu_start.tv_sec * 1000 + data->simu_start.tv_usec / 1000);
    printf("====================================\n");
    printf("\n");
}

int check_arg(char **argv, t_data **data)
{
    int philo_n;
    struct timeval start;

    philo_n = ft_atoi(argv[1]);
    if (philo_n <= 0)
    {
        printf("Error: number of philosophers must be greater than 0\n");
        return (1);
    }
    *data = malloc(sizeof(t_data) * philo_n);
    if (!(*data))
        return (1);
    for (int i = 1; i <= philo_n; i++)
    {
        (*data)[i].philo_id = i;
        printf("Philo %d initialized\n", (*data)[i].philo_id);
    }
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
    print_data(*data);
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
    {
        print_error(1, "Error: malloc failed\n");
        return (1);
    }
    printf("Start simulation\n");
    start_simulation(data);
    printf("End simulation\n");
	free (data);
    return (0);
}
