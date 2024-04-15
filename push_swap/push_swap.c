#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    create_stack(&a, argv + 1);
    if (!is_sorted(a))
    {
        ft_printf("Ordenando números...\n\n");

        if (ft_lstsize(a) == 2)
        {
            ft_printf("Acciones realizadas:\n");
            sa(&a);
            // ft_printf("\n");
            // ft_printf("Lista ordenada:\n\n");
            // while (a)
            // {
            //     ft_printf("  %d\n", a->value);
            //     a = a->next;
            // }
            // ft_printf("---\n  a\n\n");
        }
        else if (ft_lstsize(a) == 3)
        {
            ft_printf("Acciones realizadas:\n");
            sort_3(&a);
            // ft_printf("\n");
            // ft_printf("Lista ordenada:\n\n");
            // while (a)
            // {
            //     ft_printf("  %d\n", a->value);
            //     a = a->next;
            // }
            // ft_printf("---\n  a\n\n");
        }
        else
        {
            ft_printf("Acciones realizadas:\n");
            sort(&a, &b);
            ft_printf("\n");
            ft_printf("Lista ordenada:\n\n");
            while (a)
            {
                ft_printf("  %d\n", a->value);
                a = a->next;
            }
            ft_printf("---\n  a\n\n");
            while (b)
            {
                ft_printf("  %d\n", b->value);
                b = b->next;
            }
            ft_printf("---\n  b\n\n");
        }
    }
    ft_lstclear(&a);
    return (0);
}

// calculatorsoup.com/calculators/statistics/random-number-generator.php
