/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:56:08 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/29 19:55:15 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_size(t_map *map)
{
	char	*line;

	map->fd = open(map->filename, O_RDONLY);
	if (map->fd < 0)
		error_fd();
	line = get_next_line(map->fd);
	if (!line)
		return (1);
	map->x = ft_strlen(line) - 1;
	map->y = 0;
	while (line)
	{
		++map->y;
		map->base_map = ft_strjoin(map->base_map, ft_strtrim(line, "\n"));
		free(line);
		line = get_next_line(map->fd);
		if (line && (int)ft_strlen(line) - 1 != map->x)
			error_map_size(line, map, 1);
	}
	close(map->fd);
	if (map->x <= map->y)
		error_map_size(line, map, 3);
	map->width = map->x * 50;
	map->height = map->y * 50;
	return (0);
}

int	check_map_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->base_map[i])
	{
		if (map->base_map[i] != '1' && map->base_map[i] != '0'
			&& map->base_map[i] != 'P' && map->base_map[i] != 'E'
			&& map->base_map[i] != 'C')
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_valid_map(t_map *map, int pos_player)
{
	int	i;

	i = 0;
	while (map->base_map[i])
	{
		if (map->base_map[i] == 'P')
		{
			if (i != pos_player)
			{
				ft_printf("Error\n");
				return (0);
			}
		}
		if (map->base_map[i] == 'E')
			++map->chpath.exit;
		if (map->base_map[i] == 'C')
			++map->chpath.materias;
		++i;
	}
	if (map->chpath.exit != 1 || map->chpath.materias < 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	validate_sprites(t_map *map)
{
	int		i;
	int		exit;
	int		player;

	i = 0;
	exit = 0;
	player = 0;
	map->materias = 0;
	while (map->base_map[i])
	{
		if (map->base_map[i] == 'P')
			player++;
		if (map->base_map[i] == 'E')
			exit++;
		if (map->base_map[i] == 'C')
			++map->materias;
		i++;
	}
	if (player != 1 || exit != 1 || map->materias < 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	pos_player;

	if (check_map_extension(map->filename))
		return (1);
	if (check_map_size(map) || check_map_walls(map) || validate_sprites(map))
	{
		free(map->base_map);
		return (1);
	}
	pos_player = find_player_position(map);
	map->chpath.valid = 0;
	map->chpath.materias = 0;
	map->chpath.exit = 0;
	map->chpath.visited = ft_calloc(map->x * map->y, sizeof(int));
	if (!(check_valid_map(map, pos_player)))
	{
		free(&map);
		free(map->chpath.visited);
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
