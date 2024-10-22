/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:26 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 21:00:38 by davifer2         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;
typedef pthread_t t_thread;

enum e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD,
	FULL,
	GRAB_FORK,
	WAITING_SIMULATION
};

t_fork;

typedef struct s_philo
{
	long			id;
	long			last_meal;
	long			meal_count;
	int				status;
	bool			simu_on;
	t_thread		philo_thread;
	t_mutex			*print_mtx;
	t_mutex			*first_fork;
	t_mutex			*second_fork;
	t_mutex			*status_mtx;
	t_mutex			death_check;
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
	t_mutex	*forks;
	t_mutex print_mtx;
	t_philo	*philos;
}	t_data;

// MAIN FUNCTIONS
int		check_arg(t_data *data, char **args);
int		init_data(t_data *data);
void	start_simulation(t_data *data);
void	*routine(void *philo);

// UTILS FUNCTIONS
int		ft_strlen(char *str);
int		error_msg(char *msg);
int		update_status(t_philo *philo, int new_status);
long	ft_atol(const char *str);
long	get_time(void);
bool	check_status(t_philo *philo, int status);
void	ft_usleep(long miliseconds);

// FREE FUNCTIONS
int		free_philos(t_data *data, long n_philos);
void    free_forks(t_mutex **forks, int n_forks);

// TEST FUNCTIONS
void	print_data(t_data **data);


#endif
