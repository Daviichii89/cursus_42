/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 20:03:39 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong input!\nUsage: ./philo 4 800 400 400 [5]\n"));
	
	if (check_arg(&data, argv) || init_data(&data))
		return (1);
	start_simulation(&data);
	free_philos(&data, data.n_philos);
	free_forks(data.forks, data.n_philos);
	pthread_mutex_destroy(&data.print_mtx);
	return (0);
}
