#include "../push_swap.h"

int is_sorted(t_stack *a)
{
    int i;

    i = a->value;
    while (a)
    {
        if (a->value < i)
            return (0);
        i = a->value;
        a = a->next;
    }
    return (1);
}