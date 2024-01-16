/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:12 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/10 17:49:56 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_memcmp(const void *p1, const void *p2, size_t n)
{
  size_t i;
  const unsigned char *str1;
  const unsigned char *str2;

  i = 0;
  str1 = (unsigned char *)p1;
  str2 = (unsigned char *)p2;

  while (i < n)
  {
    if (*str1++ != *str2++)
      return ((int)*(str1) - (int)*(str2));
    i++;
  }
  return (0);
}
