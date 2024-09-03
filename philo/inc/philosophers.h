/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:26 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 21:03:53 by davifer2         ###   ########.fr       */
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

typedef pthread_mutex_t	t_fork;

typedef struct s_philo
{
	int				philo_id;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				last_meal;
	long			meal_count;
	pthread_t		philo_thread;
	t_fork			*left_fork;
	t_fork			*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long	n_philos;
	long	n_meals;
	long	simu_start;
	long	simu_end;
	int		dead;
	t_philo	*philo;
	t_fork	*forks;
}	t_data;

// MAIN FUNCTIONS
int		check_arg(char **args, int total_args);
int		init_data(t_data **data, char **args, int total_args);
void	start_simulation(t_data *data);
void	*routine(void *philo);

// UTILS FUNCTIONS
int		ft_strlen(char *str);
int		ft_isdigit(int c);
long	ft_atol(char *str);
void	error_msg(int fd, char *msg);

// FREE FUNCTIONS
void	free_all(t_data *data);

// TEST FUNCTIONS
void	print_data(t_data **data);


#endif
