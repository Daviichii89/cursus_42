#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int value;
	int index;
	int push_cost;
	bool above_median;
	boll cheapest;
    struct s_stack *prev;
    struct s_stack *next;
	struct s_stack *target_node;
} t_stack;

char	**ft_split(const char *s, char c);
long	ft_atol(const char *str);

void	create_stack(t_stack **a, char **argv);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **stack);

int		is_sorted(t_stack *a);
void	sort_3(t_stack **stack);
void	sort(t_stack **a, t_stack **b);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

#endif
