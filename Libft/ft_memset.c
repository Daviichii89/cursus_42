/* ************************************************************************** */
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

void *ft_memset(void *s, int c, size_t n) {
    unsigned char *p = s;
    unsigned char uc = (unsigned char)c;

    size_t i = 0;
    while (i < n) {
        p[i] = uc;
        i++;
    }

    return s;
}
