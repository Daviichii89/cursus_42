#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;
    // t_stack *b;
    t_stack *current;

    a = NULL;
    // b = NULL;
    if (argc < 2)
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    create_stack(&a, argv);
    if (!is_sorted(a))
    {
        current = a;
        printf("\nLista original:\n\n");
        while (current)
        {
            printf("  %d\n", current->value);
            current = current->next;
        }
        printf("---\n  a\n");
        printf("\nNo esta ordenada\n");
        printf("Ordenando números...\n\n");

        if (a->size == 2)
        {
            printf("Acciones realizadas:\n");
            sa(&a);
            printf("Lista ordenada:\n\n");
            while (a)
            {
                printf("  %d\n", a->value);
                a = a->next;
            }
            printf("---\n  a\n\n");
        }
        else if (a->size == 3)
        {
            printf("Acciones realizadas:\n");
            sort_3(&a);
            printf("Lista ordenada:\n\n");
            while (a)
            {
                printf("  %d\n", a->value);
                a = a->next;
            }
            printf("---\n  a\n\n");
        }
    }
    ft_lstclear(&a);
}

// calculatorsoup.com/calculators/statistics/random-number-generator.php