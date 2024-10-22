/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:38:31 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 21:05:36 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_safe_print(t_philo *philo, long timestamp)
{
	if (philo->status == FULL)
		return (false);
	return ((timestamp - philo->last_meal) <= philo->data->time_to_die);
}

static void	print_status(int new_status, t_philo *philo, long timestamp)
{
	if (new_status == DEAD)
		printf(RED"%ld %ld is dead\n"RST, timestamp, philo->id + 1);
	else if (new_status == SLEEPING)
		printf("%ld %ld is sleeping\n", timestamp, philo->id + 1);
	else if (new_status == EATING)
		printf(GRN"%ld %ld is eating\n"RST, timestamp, philo->id + 1);
	else if (new_status == THINKING)
		printf(YEL"%ld %ld is thinking\n"RST, timestamp, philo->id + 1);
	else if (new_status == GRAB_FORK)
		printf(WHT"%ld %ld has taken a fork\n"RST, timestamp, philo->id + 1);
}

void	update_print_status(int new_status, t_philo *philo)
{
	long	timestamp;

	if (pthread_mutex_lock(&philo->death_check) == -1)
		return ;
	if (pthread_mutex_lock(philo->print_mtx) == -1)
		return ;
	timestamp = get_timestamp(philo->data->simu_start);
	if (philo->data->simu_end && new_status != DEAD)
		philo->simu_on = false;
	else if (is_safe_print(philo, timestamp) || new_status == DEAD)
	{
		print_status(new_status, philo, timestamp);
		if (new_status == EATING)
		{
			philo->last_meal = timestamp;
			philo->meal_count++;
		}
		update_status(philo, new_status);
	}
	if (pthread_mutex_unlock(philo->print_mtx) == -1)
		return ;
	if (pthread_mutex_unlock(&philo->death_check) == -1)
		return ;
}