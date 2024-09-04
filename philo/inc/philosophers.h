/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:26 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/04 23:49:14 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

# define RST "\033[0m" // Reset
# define RED "\033[31m" // Red
# define GRN "\033[32m" // Green
# define YEL "\033[33m" // Yellow
# define BLU "\033[34m" // Blue
# define MAG "\033[35m" // Magenta
# define CYN "\033[36m" // Cyan
# define WHT "\033[37m" // White

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int		id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	long			meal_count;
	bool			full;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		philo_thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long	n_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	n_meals;
	long	simu_start;
	bool	simu_end;
	bool	all_ready;
	t_mtx	data_mtx;
	t_philo	*philos;
	t_fork	*forks;
}	t_data;

// MAIN FUNCTIONS
void	check_arg(t_data *data, char **args);
int		init_data(t_data *data);
void	start_simulation(t_data *data);
void	*routine(void *philo);

// UTILS FUNCTIONS
int		ft_strlen(char *str);
long	ft_atol(const char *str);
int		error_msg(char *msg);
long	get_time(t_time_code time_code);

// FREE FUNCTIONS
void	free_all(t_data *data);

// TEST FUNCTIONS
void	print_data(t_data **data);


#endif
