/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:53 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/31 19:54:35 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

//cspdiuxX %
void	ft_putchar_fd(char c, int fd);
void    ft_putnbr_fd(int	n, int fd);

int ft_printf(char const *str, ...)
{
	va_list args;
	int		i;
	
	i = 0;
	va_start(args, str);
	while(str[i])
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
			{
				//ft_puthex(va_arg(args, int), 1);
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{	
				ft_putnbr_fd(va_arg(args, int), 1);
			}
			else if (str[i] == 'u')
			{
				ft_putnbr_fd(va_arg(args, int), 1);
			}
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
	int	x = 12312312;
	int min = -2147483648;
	ft_printf("Own function result: %c %% %d\n%d\n", c, x, min);
	printf("Original result: %c %% %d\n%d\n", c, 89378923652, min);
}
