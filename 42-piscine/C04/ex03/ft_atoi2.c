/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:42:43 by davifer2          #+#    #+#             */
/*   Updated: 2023/12/13 19:42:56 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1; // Variable para manejar el signo del número
    int digit = 0;

    // Saltar espacios en blanco
    while (str[i] == ' ')
        i++;

    // Manejar el signo
    if (str[i] == '+' || str[i] == '-')
    {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Convertir dígitos a número
    while (str[i] >= '0' && str[i] <= '9')
    {
        digit = digit * 10 + (str[i] - '0');
        i++;
    }

    // Aplicar el signo al resultado
    digit *= sign;

    return digit;
}

int main(void)
{
    int result = ft_atoi("  ---+--+1234ab567");
    printf("%d\n", result);

    return 0;
}
