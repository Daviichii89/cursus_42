#include "../push_swap.h"

static int error_repetition(t_stack *a, int num)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->value == num)
            return (1);
        a = a->next;
    }
    return (0);
}

static void push_to_stack(t_stack **a, int num)
{
    t_stack *node;
    t_stack *last_node;

	if (!stack)
		return ;
    node = malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->next = NULL;
    node->value = num;
    if (!(*a))
    {
        *a = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_lstlast(*a);
        last_node->next = node;
        node->prev = last_node;
    }
}
void create_stack(t_stack **a, char **argv)
{
    int		i;
    long	num;

    i = 1;
    while (argv[i])
    {
		if (error_syntax(argv[i])
			free_errors(a);
        num = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
        if (error_repetition(*a, (int)num))
            free_errors(a);
        push_to_stack(a, (int)num);
        i++;
    }
}
