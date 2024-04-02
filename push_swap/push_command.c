#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_stack *node_to_push;

    if (!src || !*src)
        return;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (*dst)
    {
        *dst = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dst;
        node_to_push->next->prev = node_to_push;
        *dst = node_to_push;
    }
}

void pa(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}