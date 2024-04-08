#include "../push_swap.h"

static t_stack *find_biggest_node(t_stack *node)
{
    t_stack *biggest_node;

    biggest_node = node;
    while (node)
    {
        if (node->value > biggest_node->value)
            biggest_node = node;
        node = node->next;
    }
    return (biggest_node);
}

void sort_3(t_stack **a)
{
    t_stack *biggest_node;

    biggest_node = find_biggest_node(*a);
    if (biggest_node == *a)
        ra(a);
    else if (biggest_node == (*a)->next)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(stack);
}
