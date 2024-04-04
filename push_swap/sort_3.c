#include "push_swap.h"

static t_stack *find_highest_node(t_stack *stack)
{
    t_stack *highest_node;

    highest_node = stack;
    while (stack)
    {
        if (stack->value > highest_node->value)
            highest_node = stack;
        stack = stack->next;
    }
    return (highest_node);
}

void sort_3(t_stack **stack)
{
    t_stack *highest_node;

    highest_node = find_highest_node(*stack);
    if (highest_node == (*stack)->prev)
        sa(stack);
    else if (highest_node == (*stack)->next)
        rra(stack);
    else
        ra(stack);
}