/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:25:56 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/10 15:38:05 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	void	*p;

	total_size = nitems * element_size;
	p = malloc(total_size);
	if (p != NULL)
	{
		ft_memset(p, 0, total_size);
	}
	return (p);
}
