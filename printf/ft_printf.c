/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:53 by davifer2          #+#    #+#             */
/*   Updated: 2024/02/02 14:00:25 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

//cspdiuxX %
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(const char *str);

static int  ft_len_nbr(int n)
{
    int size;

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

int	ft_puthex_ptr(void *n, int fd)
{
	unsigned long long	address;
	int	rest;
	int	len;
	
	address = (unsigned long long)n;
	len = ft_len_nbr(address) + 2;
	//printf("La longitud de la address es: %d\n", len);
	write(fd, "0x", 2);
	while (len > 0)
	{
		rest = address % 16;
		char hex_digit;
		if (rest < 10)
		{
			hex_digit = rest + '0';
		}
		else
		{
			hex_digit = rest - 10 + 'a';
		}
		ft_putchar_fd(hex_digit, fd);
		address /= 16;
		len--;
	}
	return (0);
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
				//ft_putstr_fd(va_arg(args, char *), 1);
			}
			else if (str[i] == 'p')
				ft_puthex_ptr(va_arg(args, void *), 1);
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'u')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'x' || str[i] == 'X')
			{
				//ft_puthex(va_arg(args, int), 1);
			}
			else if (str[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	//char	str[] = "abc";
	char	c = 'r';
	int	x = 1;
	int min = -2147483648;
	char hex[] = "Hola";
	//ft_printf("Own function result: %c %% %d\n%d\n%X\n", c, x, min, &hex);
	//printf("Original result: %c %% %d\n%d\n%X\n", c, x, min, &hex);
	
	ft_printf("%p", &min);
	printf("\n%p", &min);
}
