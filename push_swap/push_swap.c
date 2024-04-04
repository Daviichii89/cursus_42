#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    t_stack *current;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    create_stack(&a, argv);
    current = a;
    printf("\nLista original:\n");
    while (current)
    {
        printf("  %d\n", current->value);
        current = current->next;
    }
    printf("---\n  a\n");
    if (!is_sorted(a))
    {
        printf("\nNo esta ordenada\n");
        printf("Ordenando números...\n\n");

        if (a->size == 2)
        {
            sa(&a);
            printf("Lista ordenada:\n\n");
            while (a)
            {
                printf("  %d\n", a->value);
                a = a->next;
            }
            printf("---\n  a\n\n");
        }
    }
    free_stack(&a);
}

// calculatorsoup.com/calculators/statistics/random-number-generator.php