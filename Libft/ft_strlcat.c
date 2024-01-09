/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:43:47 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/09 15:25:50 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dest;

	i = 0;
	len_src = 0;
	len_dest = 0;
	while (len_dest < size && dest[len_dest] != '\0')
		len_dest++;
	if (size == 0 || len_dest >= size)
	{
		while (src[len_dest] != '\0')
			len_dest++;
		return (len_dest);
	}
	while (src[i] != '\0' && len_dest + i < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	while (src[len_src] != '\0')
		len_src++;
	return (len_src + len_dest);
}
