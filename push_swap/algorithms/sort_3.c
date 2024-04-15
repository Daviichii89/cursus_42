#include "../push_swap.h"

t_stack *find_biggest_node(t_stack *node)
{
	long max;
	t_stack *biggest_node;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}
t_stack *find_smallest_node(t_stack *node)
{
	long min;
	t_stack *smallest_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}
void sort_3(t_stack **a)
{
	t_stack *biggest_node;

	biggest_node = find_biggest_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
