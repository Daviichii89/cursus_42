#include "push_swap.h"

static t_stack *find_biggest_node(t_stack *stack)
{
    t_stack *biggest_node;

    biggest_node = stack;
    while (stack)
    {
        if (stack->value > biggest_node->value)
            biggest_node = stack;
        stack = stack->next;
    }
    return (biggest_node);
}

void sort_3(t_stack **stack)
{
    t_stack *biggest_node;

    biggest_node = find_biggest_node(*stack);
    if (biggest_node == *stack)
        ra(stack);
    else if (biggest_node == (*stack)->next)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
}