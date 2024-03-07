/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:24 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/19 19:13:06 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
void	delete_node(void *content)
{
	free(content);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	if (!(*lst))
	{
		//(*del)((*lst)->content);
		//free(*lst);
		ft_lstdelone((*lst), del);
		return ;
	}
	while (*lst != NULL)
	{
		current = (*lst)->next;
		//(*del)((*lst)->content);
		//free(*lst);
		ft_lstdelone((*lst), del);
		*lst = current;
	}
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	*node;

	node = ft_lstnew("hello");
	printf("Content %s\n", (char *)node->content);
	
	ft_lstdelone(node, delete_node);
	printf("Content %s\n", (char *)node->content);

	return (0);
}*/
