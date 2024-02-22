/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:02:46 by davifer2          #+#    #+#             */
/*   Updated: 2024/02/22 15:02:04 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_max(int nb)
{
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
	}
	return (11);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (n == -2147483648)
		return (ft_putnbr_max(n));
	else
	{
		if (n < 0)
		{
			if (ft_putchar_fd('-', fd) == -1)
				return (-1);
			n = -n;
		}
		if (n > 9)
			if (ft_putnbr_fd(n / 10, fd) == -1)
				return (-1);
		if (ft_putchar_fd(n % 10 + '0', fd) == -1)
			return (-1);
	}
	return (ft_nbrlen(nbr));
}
/*
int main()
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
