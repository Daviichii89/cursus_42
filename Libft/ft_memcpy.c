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

void *ft_memcpy(void *dst, const void *src, size_t n)
{
  size_t i;
  char *dest_p;
  const char *src_p;

  i = 0;
  dest_p = (char *)dst;
  src_p = (char *)src;
  while (dst == src || !dst && !src)
  {
    return (dst);
  }
  while (i < n)
  {
    dest_p[i] = src_p[i];
    i++;
  }
  return (dst);
}
