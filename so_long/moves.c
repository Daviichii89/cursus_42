/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/29 18:02:16 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	ft_collect_materia(t_window *window, int player_pos)
{
	window->map->base_map[player_pos] = '0';
	--window->map->materias;
}

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
			ft_printf("No puedes salir.\n");
			return (1);
		}
		ft_printf("Has ganado!\n");
		mlx_destroy_window(window->mlx_ptr, window->window_ptr);
		exit(0);
	}
	++window->movements;
	return (0);
}

void	move_w(t_window *window)
{
	window->player.pos_y -= 50;
	if (ft_validate_movement(window))
		window->player.pos_y += 50;
}

void	move_a(t_window *window)
{
	window->player.pos_x -= 50;
	if (ft_validate_movement(window))
		window->player.pos_x += 50;
}

void	move_s(t_window *window)
{
	window->player.pos_y += 50;
	if (ft_validate_movement(window))
		window->player.pos_y -= 50;
}

void	move_d(t_window *window)
{
	window->player.pos_x += 50;
	if (ft_validate_movement(window))
		window->player.pos_x -= 50;
}
