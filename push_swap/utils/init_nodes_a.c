#include "../push_swap.h"

void init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_in_a(a, b);
	set_cheapest(a);
}
