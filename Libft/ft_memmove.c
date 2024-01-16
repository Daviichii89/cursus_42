/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:07:08 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/10 17:51:54 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
  const unsigned char *str_ptr;
  unsigned char *dst_ptr;
  int i;

  str_ptr = src;
  dst_ptr = dest;
  i = 0;
  if (dest == src)
    return (dest);
  while (i < n)
  {
    dst_ptr[i] = str_ptr[i];
    i++;
  }
  return (dest);
}
int main()
{
  // Ejemplo de uso
  char source[] = "Hello, World!";
  char destination[20];

  ft_memmove(destination, source, 13);

  // Imprimir el resultado
  printf("Source: %s\n", source);
  printf("Destination: %s\n", destination);

  return 0;
}
