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
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
    int	*left_fork;
    int	*right_fork;
    struct s_data	*data;
}				t_philo;

typedef struct s_data
{
    int				n_philos;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				philo_eats;
    int				*meals;
    int				start_time;
    t_philo			*philos;
}				t_data;

int		ft_atoi(const char *str);
void	ft_usleep(int time);

#endif