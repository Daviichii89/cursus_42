#include "../push_swap.h"

static int error_syntax(char *str_n)
{
    if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
        return (1);
    if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
        return (1);
    while (*++str_n)
    {
        if (!(*str_n >= '0' && *str_n <= '9'))
            return (1);
    }
    return (0);
}

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

    if (!a)
        return;
    node = malloc(sizeof(t_stack));
    if (!node)
        return;
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
    int i;
    long num;

    i = 0;
    while (argv[i])
    {
        if (error_syntax(argv[i]))
        {
            ft_printf("Error\n");
            ft_lstclear(a);
            exit(1);
        }
        num = ft_atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            ft_printf("Error\n");
            ft_lstclear(a);
            exit(1);
        }
        if (error_repetition(*a, (int)num) == 1)
        {
            ft_printf("Error\n");
            ft_lstclear(a);
            exit(1);
        }
        push_to_stack(a, (int)num);
        i++;
    }
}
