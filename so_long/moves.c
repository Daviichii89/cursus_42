/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/30 16:32:53 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static int	ft_validate_movement(t_window *window)
{
	int		player_pos;
	int		y;
	int		x;
	char	map_pos;

	y = window->player.pos_y / 50;
	x = window->player.pos_x / 50;
	player_pos = x + (y * window->map->x);
	map_pos = window->map->base_map[player_pos];
	if (map_pos == '1')
		return (1);
	else if (map_pos == 'C')
		ft_collect_materia(window, player_pos);
	else if (map_pos == 'E')
	{
		if (window->map->materias != 0)
		{
			perror("No puedes salir.\n");
			return (1);
		}
		ft_printf("\n\n\n	🥳🥳 Has ganado! 🥳🥳\n\n\n");
		exit_program(window);
	}
	return (0);
}

void	move_w(t_window *window)
{
	window->player.pos_y -= 50;
	if (ft_validate_movement(window))
		window->player.pos_y += 50;
	else
	{
		window->movements++;
		ft_printf("Movimientos: %d\n", window->movements);
	}
}

void	move_a(t_window *window)
{
	window->player.pos_x -= 50;
	if (ft_validate_movement(window))
		window->player.pos_x += 50;
	else
	{
		window->movements++;
		ft_printf("Movimientos: %d\n", window->movements);
	}
}

void	move_s(t_window *window)
{
	window->player.pos_y += 50;
	if (ft_validate_movement(window))
		window->player.pos_y -= 50;
	else
	{
		window->movements++;
		ft_printf("Movimientos: %d\n", window->movements);
	}
}

void	move_d(t_window *window)
{
	window->player.pos_x += 50;
	if (ft_validate_movement(window))
		window->player.pos_x -= 50;
	else
	{
		window->movements++;
		ft_printf("Movimientos: %d\n", window->movements);
	}
}
