#include "../push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *current;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    while (last->next)
        last = last->next;
    current = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next = current;
    current->prev = last;
    current->next = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    // write(1, "ra\n", 3);
    printf("ra -> Rotar el primero al último.\n");
}

void rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}