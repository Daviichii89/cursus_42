/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/19 11:35:18 by davifer2         ###   ########.fr       */
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
	if (map_pos == '0')
		ft_printf("Hay suelo");
	return (0);
}

void	move_w(t_map *map)
{
	int			i;
	t_window	window;

	i = 0;
	while (map->base_map[i] != 'P')
		i++;
	window.player.pos_y += 50;
	if (ft_validate_movement(&window))
		ft_printf("Valido\n");
}

void	move_a(t_map *map)
{
	(void)map;
}

void	move_s(t_map *map)
{
	(void)map;
}

void	move_d(t_map *map)
{
	t_window	window;

	(void)map;
	if (ft_validate_movement(&window))
		ft_printf("Valido\n");
}
