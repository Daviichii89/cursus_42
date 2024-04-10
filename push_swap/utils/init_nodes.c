#include "../push_swap.h"

void	init_nodes_a(t_stack *a, t_stack *b)
{
	printf("Hola entro en init a");
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_in_a(a, b);
	set_cheapest(a);
}
void	init_nodes_b(t_stack *a, t_stack *b)
{
	printf("Hola entro en init b");
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
