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
        printf("Ordenando números...\n\n");

        if (ft_lstsize(a) == 2)
        {
            printf("Acciones realizadas:\n");
            sa(&a);
            printf("\n");
            printf("Lista ordenada:\n\n");
            while (a)
            {
                printf("  %d\n", a->value);
                a = a->next;
            }
            printf("---\n  a\n\n");
        }
        else if (ft_lstsize(a) == 3)
        {
            printf("Acciones realizadas:\n");
            sort_3(&a);
            printf("\n");
            printf("Lista ordenada:\n\n");
            while (a)
            {
                printf("  %d\n", a->value);
                a = a->next;
            }
            printf("---\n  a\n\n");
        }
        else
        {
            ft_printf("Mas de 3 números\n");
            ft_printf("Acciones realizadas:\n");
            sort(&a, &b);
            printf("\n");
            printf("Lista ordenada:\n\n");
            while (a)
            {
                printf("  %d\n", a->value);
                a = a->next;
            }
            printf("---\n  a\n\n");
            while (b)
            {
                printf("  %d\n", b->value);
                b = b->next;
            }
            printf("---\n  b\n\n");
        }
    }
    ft_lstclear(&a);
    return (0);
}

// calculatorsoup.com/calculators/statistics/random-number-generator.php
