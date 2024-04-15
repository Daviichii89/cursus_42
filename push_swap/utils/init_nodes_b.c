#include "../push_swap.h"

void init_nodes_b(t_stack *a, t_stack *b)
{
	ft_printf("Hola entro en init b\n");
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
