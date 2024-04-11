#include "../push_swap.h"

static void swap(t_stack **stack)
{
    int len;

    len = ft_lstsize(*stack);
    if (len < 2 || !*stack || !(*stack)->next)
        return;
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
}

void sa(t_stack **a)
{
    swap(a);
    ft_printf("sa -> Intercambio de posiciones\n\n");
}
void sb(t_stack **b)
{
    swap(b);
	ft_printf("sb -> Intercambio de posiciones\n\n");
}
void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
	ft_printf("ss -> Intercambio de posiciones\n\n");
}
