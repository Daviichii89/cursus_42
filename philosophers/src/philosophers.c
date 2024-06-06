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

#include "../inc/philosophers.h"

int check_arg(char *n_arg, int pos, t_data *data)
{
    int     n;

    n = ft_atoi(n_arg);
    if (n <= 0)
    {
        free(data);
        printf("Error\nIncorrect number of arguments.\n");
        return (1);
    }
    else
    {
        if (pos == 1)
            data->n_philos = n;
        else if (pos == 2)
            data->time_to_die = n;
        else if (pos == 3)
            data->time_to_eat = n;
        else if (pos == 4)
            data->time_to_sleep = n;
        else if (pos == 5)
            data->philo_eats = n;
        return (n);
    }
}

                                  

int main(int argc, char **argv)
{
    int     i;
    t_data  *data;

    if (argc != 5 && argc != 6)
    {
        printf("Error: wrong number of arguments\n");
        return (1);
    }
    i = 1;
    data = malloc(sizeof(t_data));
    if (!data)
        return (1);
    while (i != argc)
    {
        if (check_arg(argv[i], i, data))
            return (1);
        i++;
    }

    return (0);
}