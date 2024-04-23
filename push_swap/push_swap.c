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

static void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void free_memory(t_stack *a, char **result_split)
{
    if (result_split)
        free_argv(result_split);
    ft_lstclear(&a);
}

void	algorithm_selection(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
	}
}

void initialize_stacks(t_stack **a, t_stack **b, char ***result_split)
{
	*a = NULL;
	*b = NULL;
	*result_split = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**result_split;

	initialize_stacks(&a, &b, &result_split);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		result_split = ft_split(argv[1], ' ');
		create_stack(&a, result_split);
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
	free_memory(a, result_split);
	return (0);
}
// calculatorsoup.com/calculators/statistics/random-number-generator.php
