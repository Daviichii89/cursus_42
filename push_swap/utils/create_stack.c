#include "../push_swap.h"

//static void	free_errors(t_stack **a)
//{
	//ft_printf("%d\n", a.value); 
//}

static int	error_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

static int error_repetition(t_stack *a, int num)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->value == num)
            return (1);
        a = a->next;
    }
    return (0);
}

static void push_to_stack(t_stack **a, int num)
{
    t_stack *node;
    t_stack *last_node;

	if (!a)
		return ;
    node = malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->next = NULL;
    node->value = num;
    if (!(*a))
    {
        *a = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_lstlast(*a);
        last_node->next = node;
        node->prev = last_node;
    }
}
void create_stack(t_stack **a, char **argv)
{
    int		i;
    long	num;

    i = 1;
    while (argv[i])
    {
		if (error_syntax(argv[i]) == 1)
		{
			ft_printf("Error syntax.\n");
			ft_lstclear(a);
			exit(1);
		}
        num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error overflow.\n");
			ft_lstclear(a);
			exit(1);
		}
		if (error_repetition(*a, (int)num) == 1)
		{
            ft_printf("Error duplicate.\n");
			ft_lstclear(a);
			exit(1);
		}
        push_to_stack(a, (int)num);
        i++;
    }
}
