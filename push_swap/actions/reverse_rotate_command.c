#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
    t_stack *last_node;
    
    if (!*stack || !(*stack)->next)
        return;
    last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
    last_node->prev = NULL;
    *stack = last_node;
    last_node->next->prev = last_node;
}

void	rra(t_stack **a)
{
    reverse_rotate(a);
    ft_printf("rra -> Rotar el último al primero.\n");
}

void	rrb(t_stack **b)
{
    reverse_rotate(b);
	ft_printf("rrb -> Rotar el último al primero.\n");
}


void	rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
	ft_printf("rrr -> Rotar el último al primero en ambos.\n");
}
