#include "../push_swap.h"

void pa(t_stack **src, t_stack **dst)
{
    t_stack *node_to_push;

    write(1, "pa\n", 3);
    if (!*src)
        return;
    node_to_push = *dst;
    *dst = *src;
    *src = (*src)->next;
    (*dst)->next = node_to_push;
}

void pb(t_stack **src, t_stack **dst)
{
    t_stack *node_to_push;
    write(1, "pb\n", 3);
    if (!*src)
        return;
    node_to_push = *dst;
    *dst = *src;
    *src = (*src)->next;
    (*dst)->next = node_to_push;
}