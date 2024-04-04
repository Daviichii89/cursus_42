#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
void sort_3(t_stack **stack);
void sort_5(t_stack **a, t_stack **b);
void sort(t_stack **a, t_stack **b);

void create_stack(t_stack **a, char **argv);
int ft_lstsize(t_stack *lst);
t_stack *ft_lstlast(t_stack *lst);
void free_stack(t_stack **a);

void sa(t_stack **a);
void ra(t_stack **a);
void rra(t_stack **a);

#endif