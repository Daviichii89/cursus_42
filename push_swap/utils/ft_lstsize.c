/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:21:54 by davifer2          #+#    #+#             */
/*   Updated: 2024/04/16 11:34:17 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
int main(void)
{
	t_list	*node;

	node = ft_lstnew("hello");
	printf("%s\n", (char *)node->content);
	printf("La longitud del contenido de la lista es: %d\n", ft_lstsize(node));
	return (0);
}*/
