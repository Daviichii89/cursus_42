/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 09:14:12 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_data(t_data **data)
{
	printf("Number of philosophers: %ld\n", (*data)->n_philos);
	printf("Time to die: %ld\n", (*data)->philo[0].time_to_die);
	printf("Time to eat: %ld\n", (*data)->philo[0].time_to_eat);
	printf("Time to sleep: %ld\n", (*data)->philo[0].time_to_sleep);
	printf("Number of meals: %ld\n", (*data)->n_meals);
	
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
	{
		error_msg(2, "Usage: ");
		error_msg(2, "Example: ./philo 4 800 400 400 [number_of_meals]\n");
		return (1);
	}
	if (check_arg(argv, argc))
	{
		error_msg(2, "Error: malloc failed\n");
		return (1);
	}
	if (init_data(&data, argv, argc))
	{
		error_msg(2, "Error: malloc failed\n");
		return (1);
	}
	print_data(&data);
	printf("Start simulation\n");
	// start_simulation(data);
	printf("End simulation\n");
	free_all(data);
	return (0);
}
