#include "push_swap.h"

int ft_check_duplicates(t_stack *a)
{
    t_stack *tmp;

    while (a)
    {
        tmp = a->next;
        while (tmp)
        {
            if (a->value == tmp->value)
                return (1);
            tmp = tmp->next;
        }
        a = a->next;
    }
    return (0);
}