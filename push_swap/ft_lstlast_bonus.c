/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:10 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/20 15:07:40 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack *ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
	t_list	*node1;
	t_list	*node2;

	node1  = ft_lstnew("hello");
	node2 = ft_lstnew("world");
	ft_lstadd_front(&node1, node2);

	t_list *last_node = ft_lstlast(node1);
	if (last_node != NULL)
		printf("Valor ultimo node: %s\n", (char *)last_node->content);


	t_list *current = node1;
	t_list *temp;
	int i = 1;

	while (current != NULL)
	{
		printf("Vuelta %d: %s\n", i, (char *)current->content);
		temp = current->next;
		free(current);
		current = temp;
		i++;
	}
	return(0);
}*/
