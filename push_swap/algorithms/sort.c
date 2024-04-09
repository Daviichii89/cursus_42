#include "../push_swap.h"

static void	verify_if_on_top(t_stack **stack, t_stack *top_node, char stack_name)
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
static void move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapes_node = get_cheapest(*a);
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
static void	min_on_top(t_stack **a, t_stack **b)
{
	while ((*a)->value != find_smallest_node(*a)->nbr)
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

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
