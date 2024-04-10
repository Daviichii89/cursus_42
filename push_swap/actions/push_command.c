#include "../push_swap.h"

void pa(t_stack **src, t_stack **dst)
{
    t_stack *node_to_push;

    write(1, "pa\n", 3);
    if (!*src)
        return;
    node_to_push = *dst;
    *dst = *src;
    *src = (*src)->next;
    (*dst)->next = node_to_push;
}

void pb(t_stack **src, t_stack **dst)
{
	//t_stack *dest;
    t_stack *node_to_push;
	static int	i = 1;

    printf("pb %d\n", i);
    if (!*src)
	{
		printf("Salgo %d\n", i);
        return ;
	}
    node_to_push = *dst;
    *dst = *src;
    *src = (*src)->next;
    (*dst)->next = node_to_push;
	//dest = node_to_push;
	while (*dst)
	{
		printf("\n  %d\n", (*dst)->value);
		*dst = (*dst)->next;
	}
	printf("---\n  b\n");
	i++;
}
