/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:00:29 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/03 19:17:11 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(char **args, int total_args)
{
	int	i;
	int	j;

	i = 1;
	while (i < total_args)
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				printf("args[%d][%d] = %c\n", i, j, args[i][j]);
				error_msg(2, "Error: wrong input format\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
