#include "push_swap.h"

static void swap(t_stack **stack)
{
    int len;

    len = stack_len(*stack);
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
    write(1, "sa\n", 3);
}
void sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}
void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}