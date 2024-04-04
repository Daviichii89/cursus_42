#include "../push_swap.h"

static void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *current;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    while (last->next)
        last = last->next;
    current = last->prev;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
    current->next = NULL;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    // write(1, "rra\n", 4);
    printf("rra -> Rotar el último al primero.\n\n");
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}