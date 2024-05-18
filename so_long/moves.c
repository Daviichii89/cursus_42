/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:20 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/18 16:06:47 by davifer2         ###   ########.fr       */
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
	ft_printf("y %d\n", window->player.pos_y);
	x = window->player.pos_x / 50;
	ft_printf("x %d\n", window->player.pos_x);
	player_pos = x + (y * window->map->x);
	 ft_printf("player pos\n");
	map_pos = window->map->base_map[player_pos];
	 ft_printf("map pos\n");
	if(map_pos == '0')
		ft_printf("Hay suelo");
	return (0);
}

void move_w(t_map *map)
{
	int i;
	t_window window;

	i = 0;
	while(map->base_map[i] != 'P')
		i++;
	window.player.pos_y += 50;
	
	if (ft_validate_movement(&window))
		ft_printf("Valido\n");
		//window.player.pos_y += 50;
			
}

void move_a(t_map *map)
{
	(void)map;
}

void move_s(t_map *map)
{
	(void)map;
}

void move_d(t_map *map)
{
//	int i;
	(void)map;
	t_window window;
	ft_printf("tecla d presionada here\n");
//	i = 0;
	/*
	while(map->base_map[i] != 'P')
		i++;*/
	ft_printf("tecla d presionada\n");
	//window.player.pos_x += 50;
	if(ft_validate_movement(&window))
		ft_printf("Valido\n");
		//window.player.pos_x -= 50;
}
