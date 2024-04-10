#include "../push_swap.h"

bool	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
    while (a->next)
    {
        if (a->value > a->next->value)
            return (false);
        a = a->next;
    }
    return (true);
}
