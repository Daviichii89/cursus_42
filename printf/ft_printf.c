/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:53 by davifer2          #+#    #+#             */
/*   Updated: 2024/02/14 13:47:58 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_len_nbr(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static int	ft_puthex(unsigned long long n, int fd)
{
	unsigned long long	nbr;
	int					len;

	nbr = (unsigned long long)n;
	len = ft_len_nbr(nbr) + 2;
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, fd);
		ft_puthex(nbr % 16, fd);
	}
	else
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', fd);
		else
			ft_putchar_fd(nbr - 10 + 'a', fd);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
			}
			else if (str[i] == 'p')
			{
				write(1, "0x", 2);
				ft_puthex(va_arg(args, unsigned long long), 1);
			}
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'u')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'x' || str[i] == 'X')
			{
				ft_puthex(va_arg(args, unsigned long long), 1);
			}
			else if (str[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
/*
int main(void)
{
	//char	str[] = "abc";
	char	c = 'r';
	int	x = 1;
	int min = -2147483648;
	char s[] = "Hola";
	//ft_printf("Own function result: %c %% %d\n%d\n%X\n", c, x, min, &hex);
	//printf("Original result: %c %% %d\n%d\n%X\n", c, x, min, &hex);
	
	ft_printf("%s", s);
	//ft_printf("Own: %p", &x);
	//printf("\nOriginal: %p\n", &x);
}*/
