/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:27:37 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/04 19:42:08 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static const char	*valid_input(const char *str)
{
	int	len;
	const char	*nbr;

	len = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_msg("Must be a positive number");
	while (*str == '0')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		error_msg("Must be a number");
	nbr = str;
	while (ft_isdigit(*str))
	{
		len++;
		str++;
	}
	if (len > 10)
		error_msg("Number too big");
	return (nbr);
}

long	ft_atol(const char *str)
{
	long		res;

	res = 0;
	if (!str)
		error_msg("Null pointer");
	str = valid_input(str);
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	if (res > INT_MAX)
		error_msg("Number too big");
	return (res);
}

int    ft_strlen(char *str)
{
    int	i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}