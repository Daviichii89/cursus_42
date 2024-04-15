#include "../push_swap.h"

static void push(t_stack **dst, t_stack **src)
{
	t_stack *push_node;

	if (!*src)
		return;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}