/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 21:05:10 by davifer2         ###   ########.fr       */
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
		return (1);
	if (init_data(&data, argv, argc))
		return (1);
	start_simulation(data);
	free_all(data);
	return (0);
}
