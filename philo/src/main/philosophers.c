/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:41:03 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/21 00:08:08 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
	{
		print_error(1, "Error: wrong number of arguments\n");
		return (1);
	}
	if (check_arg(argv, &data))
	{
		print_error(1, "Error: malloc failed\n");
		return (1);
	}
	init_data(data);
	printf("Start simulation\n");
	start_simulation(data);
	printf("End simulation\n");
	free_all(data);
	return (0);
}
