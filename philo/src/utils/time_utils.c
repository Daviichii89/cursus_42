/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:23:10 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/22 22:25:33 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long miliseconds)
{
	long	start_time;
	long	elapsed;

	start_time = get_time();
	elapsed = get_timestamp(start_time);
	while (miliseconds > elapsed)
	{
		usleep(200);
		elapsed = get_timestamp(start_time);
	}
}

long    get_timestamp(long simu_start)
{
    return (get_time() - simu_start);
}

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error_msg("Error getting time\n"));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}