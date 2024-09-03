/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 11:25:56 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	printf("=================\n");
	printf("Start simulation\n");
	printf("=================\n");
	start_simulation(data);
	printf("=================\n");
	printf("End simulation\n");
	printf("=================\n");
	free_all(data);
	return (0);
}
