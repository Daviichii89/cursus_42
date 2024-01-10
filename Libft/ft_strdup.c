/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:58 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/09 15:40:28 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	str = (char *) maloc (sizeof(*str) * (size));
	while (i < size)
	{
		str[i] + src[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}
