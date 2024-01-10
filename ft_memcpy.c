/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:50:22 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/10 17:50:30 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (dst == src || !n)
	{
		return (dst);
	}
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
