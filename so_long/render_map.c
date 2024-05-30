/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:21:07 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/30 13:09:05 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_specials(t_window *window, char *map_pos, int x, int y)
{
	if (*map_pos == 'C')
		mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
			window->background.collectible, x * 50, y * 50);
	if (*map_pos == '1')
		mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
			window->background.bush, x * 50, y * 50);
	if (*map_pos == 'E')
		mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
			window->background.imgexit, x * 50, y * 50);
	if (*map_pos == 'P')
	{
		window->player.pos_x = x * 50;
		window->player.pos_y = y * 50;
		*map_pos = '0';
	}
}

static void	render_background(t_window *window)
{
	int		y;
	int		x;
	int		i;
	char	*map_pos;

	y = 0;
	i = 0;
	while (y < window->map->y)
	{
		x = 0;
		while (x < window->map->x)
		{
			map_pos = &window->map->base_map[i];
			if (ft_strchr("0PC", *map_pos))
				mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
					window->background.imgfloor, x * 50, y * 50);
			if (ft_strchr("C1EP", *map_pos))
				render_specials(window, map_pos, x, y);
			x++;
			i++;
		}
		y++;
	}
}

int	render_map(t_window *window)
{
	render_background(window);
	mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
		window->player.down, window->player.pos_x, window->player.pos_y);
	return (0);
}
