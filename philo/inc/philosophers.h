/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:26 by davifer2          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:05 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
    int                     philo_id;
    int				        n_philos;
    int				        time_to_die;
    int				        time_to_eat;
    int				        time_to_sleep;
    int				        philo_eats;
    int				        *meals;
    struct timeval          simu_start;
    pthread_mutex_t			*forks;
    pthread_mutex_t			*print_mutex;
}				t_data;

int		ft_atoi(const char *str);
void    *routine(void *philo);

#endif
