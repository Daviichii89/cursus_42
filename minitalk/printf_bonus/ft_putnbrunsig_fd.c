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

int	ft_putnbrunsig_fd(unsigned int n, int fd)
{
	if (n < 10)
	{
		if (ft_putchar_fd(n + '0', fd) == -1)
			return (-1);
	}
	else
	{
		if (ft_putnbrunsig_fd(n / 10, fd) == -1)
			return (-1);
		if (ft_putnbrunsig_fd(n % 10, fd) == -1)
			return (-1);
	}
	return (ft_nbrunsiglen(n));
}
