/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:08:54 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 21:09:33 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_mutex	*get_first_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (philo->first_fork);
	return (philo->second_fork);
}

t_mutex	*get_second_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (philo->second_fork);
	return (philo->first_fork);
}