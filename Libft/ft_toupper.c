# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:27:33 by davifer2          #+#    #+#              #
/*   Updated: 2024/01/09 13:48:20 by davifer2         ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return c;
	}
	return c
}
