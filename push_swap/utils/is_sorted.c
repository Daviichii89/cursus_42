#include "../push_swap.h"

bool	is_sorted(t_stack *a)
{
	if (!stack)
		return (1);
    while (a->next)
    {
        if (a->value > stack->next->value)
            return (false);
        a = a->next;
    }
    return (true);
}
