/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:03:14 by davifer2          #+#    #+#             */
/*   Updated: 2024/04/19 16:24:59 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[i] && flag == 1)
	{
		free(argv[i++]);
	}
	free(argv);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		create_stack(&a, argv);
	}
	else
		create_stack(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
	}
	free_argv(argv);
	ft_lstclear(&a);
	return (0);
}
// calculatorsoup.com/calculators/statistics/random-number-generator.php
