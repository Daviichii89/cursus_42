#include "../push_swap.h"

void init_nodes_a(t_stack *a, t_stack *b)
{
	ft_printf("Hola entro en init a\n");
	current_index(a);
	ft_printf("El número %d tiene el index: %d\n", a->value, a->index);
	current_index(b);
	set_target_a(a, b);
	cost_in_a(a, b);
	set_cheapest(a);
}
