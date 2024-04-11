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

	printf("Entro en sort_3\n");
	printf("El valor del nodo 1 es %d\n", (*a)->value);
	biggest_node = find_biggest_node(*a);
	printf("El valor del nodo mas grande es %d\n", biggest_node->value);
	if (biggest_node == *a)
	{
		printf("Entro en ra\n");
		ra(a);
	}
	else if ((*a)->next == biggest_node)
	{
		printf("Entro en rra\n");
		rra(a);
	}
	if ((*a)->value > (*a)->next->value)
	{
		printf("Entro en sa\n");
		sa(a);
	}
}
