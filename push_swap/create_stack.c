#include "push_swap.h"

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

    if (!*a)
        return;
    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->next = NULL;
    node->value = num;
    if (!*a)
    {
        *a = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*a);
        last_node->next = node;
        node->prev = last_node;
    }
}
void create_stack(t_stack **a, char **argv)
{
    int i;
    int num;

    i = 0;
    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        if (error_repetition(*a, num))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        push_to_stack(a, num);
        i++;
    }
}