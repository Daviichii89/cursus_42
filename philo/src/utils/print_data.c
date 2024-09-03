/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:21:34 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 14:32:23 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_data(t_data **data)
{
	int	i;

	i = -1;
	printf("===========================\n");
	printf("=== 	 Data		===\n");
	printf("===========================\n");
	printf("Number of philosophers: %ld\n", (*data)->n_philos);
	printf("Time to die: %ld\n", (*data)->philo[0].time_to_die);
	printf("Time to eat: %ld\n", (*data)->philo[0].time_to_eat);
	printf("Time to sleep: %ld\n", (*data)->philo[0].time_to_sleep);
	printf("Number of meals: %ld\n", (*data)->n_meals);
	while (i++ < (*data)->n_philos - 1)
		printf("ID: %d\n", (*data)->philo[i].philo_id);
	printf("===========================\n");
	
}