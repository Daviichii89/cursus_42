#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
    t_stack *last_node;

    if (!*stack || !(*stack)->next)
        return;
    last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void	ra(t_stack **a)
{
    rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
