#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	create_stack(&a, argv);
	if (!is_sorted(a))
	{
		if (a->size <= 3)
			sort_3(&a);
		else if (a->size <= 5)
			sort_5(&a, &b);
		else
			sort(&a, &b);
	}
	free_stack(&a);
}
