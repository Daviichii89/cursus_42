#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    int index;
    int size;
    int current_position;
    struct s_stack *target_node;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

char **ft_split(const char *s, char c);
int ft_atoi(const char *str);

int is_sorted(t_stack *a);
void sort_3(t_stack **a);
void sort_5(t_stack **a, t_stack **b);
void sort(t_stack **a, t_stack **b);
void free_stack(t_stack **a);

void create_stack(t_stack **a, char **argv);
t_stack *ft_lstlast(t_stack *lst);
int ft_lstsize(t_stack *lst);

#endif