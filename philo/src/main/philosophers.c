/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/09 21:42:58 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong input!\nUsage: ./philo 4 800 400 400 [5]\n"));
	check_arg(&data, argv);
	if (init_data(&data))
		return (1);
	start_simulation(&data);
	// free_all(&data);
	return (0);
}
