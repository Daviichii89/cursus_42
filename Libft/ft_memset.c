i/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:28:00 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/09 15:30:39 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memset(void *s, int c, size_t n) {
    unsigned char	*str;
    int i;

    str = b;
    i = 0;
    while (i < n) {
        str[i] = (unsigned char)c;
        i++;
    }

    return (s);
}
