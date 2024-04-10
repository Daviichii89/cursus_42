#include "../push_swap.h"

void	verify_if_on_top(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static t_stack	*get_cheapest(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
void move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		current_index(*a);
		current_index(*b);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		current_index(*a);
		current_index(*b);
	}
	verify_if_on_top(a, cheapest_node, 'a');
	verify_if_on_top(b, cheapest_node->target_node, 'b');
	pb(b, a);
}
static void move_b_to_a(t_stack **a, t_stack **b)
{
	verify_if_on_top(a, (*b)->target_node, 'a');
	pa(a, b);
}
static void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_smallest_node(*a)->value)
	{
		if (find_smallest_node(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
void	sort(t_stack **a, t_stack **b)
{
	int	len_a;
	//t_stack	*current = *a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
	{
		ft_printf("\n\nPush a b 1\n");
		pb(a, b);
	}
	if (len_a-- > 3 && !is_sorted(*a))
	{
		ft_printf("\n\nPush a b 2\n");
		pb(a, b);
	}
	while (len_a > 3 && !is_sorted(*a))
	{
		ft_printf("Sigo aqui porque hay mas de 3 números\n");
		ft_printf("Cantidad nodos: %d\n", len_a);
		pb(a, b);
		/*while (a)
		{
			printf("\n%d\n", (*a)->value);
			*a = (*a)->next;
		}*/
		len_a--;
		//init_nodes_a(*a, *b);
		//move_a_to_b(a, b);
	}
	ft_printf("\n\nAhora solo tengo 3 números\n");
	sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
