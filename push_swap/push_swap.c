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
    {
        argv = ft_split(argv[1], ' ');
        create_stack(&a, argv);
    }
    else
        create_stack(&a, argv + 1);
    if (!is_sorted(a))
    {
        if (ft_lstsize(a) == 2)
            sa(&a);
        else if (ft_lstsize(a) == 3)
            sort_3(&a);
        else
            sort(&a, &b);
    }
    ft_lstclear(&a);
    return (0);
}
// calculatorsoup.com/calculators/statistics/random-number-generator.php