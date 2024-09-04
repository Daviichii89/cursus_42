/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:26:22 by davifer2          #+#    #+#             */
/*   Updated: 2024/09/04 22:39:22 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int error_msg(char *msg)
{
    write(2, RED, ft_strlen(RED));
    write(2, msg, ft_strlen(msg));
    write(2, RST, ft_strlen(RST));
    return (1);
}