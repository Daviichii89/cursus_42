/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:26 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/27 09:28:14 by davifer2         ###   ########.fr       */
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
# include <limits.h>

typedef struct s_data	t_data;

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int				philo_id;
	long			meal_count;
	long			max_meals;
	long			meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	philo_mutex;
	pthread_t		philo_thread;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	long	n_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	n_meals;
	long	simu_start;
	t_fork	*forks;
	t_philo	*philos;
}	t_data;

int		check_arg(char **argv, t_data **data);
void	init_data(t_data *data);
void	start_simulation(t_data *data);
void	*routine(void *philo);

int		ft_strlen(char *str);
void	error_msg(int fd, char *msg);
void	free_all(t_data *data);

#endif
