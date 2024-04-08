#include "../push_swap.h"

void sort_5(t_stack **a, t_stack **b)
{
    t_stack *current;
    t_stack *smallest_node;
    t_stack *second_smallest_node;

    // Encontrar el nodo más pequeño
    smallest_node = *a;
    current = (*a)->next;
    while (current)
    {
        if (current->value < smallest_node->value)
            smallest_node = current;
        current = current->next;
    }

    // Encontrar el segundo nodo más pequeño
    second_smallest_node = (*a == smallest_node) ? (*a)->next : *a;
    current = (*a)->next;
    while (current)
    {
        if (current != smallest_node && current->value < second_smallest_node->value)
            second_smallest_node = current;
        current = current->next;
    }
    sort_3(a);
    pa(b, a);
    pa(b, a);
}