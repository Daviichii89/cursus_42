/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:27:44 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/29 20:07:03 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	find_player_position(t_map *map)
{
	int	i;

	i = 0;
	while (map->base_map[i] != 'P')
		i++;
	return (i);
}

int	check_map_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i > 2 && filename[i - 4] != '.' && filename[i - 3] != 'b'
		&& filename[i - 2] != 'e' && filename[i - 1] != 'r')
	{
		ft_printf("Error\nExtension del archivo invalida\n");
		return (1);
	}
	return (0);
}

int	error_map_size(char *line, t_map *map, int error_code)
{
	if (error_code == 1)
	{
		ft_printf("Error\nEl mapa no es rectangular.\n");
		close(map->fd);
		free(line);
		return (1);
	}
	else if (error_code == 2)
	{
		ft_printf("Error\nNo se pudo abrir el archivo\n");
		return (1);
	}
	else if (error_code == 3)
	{
		ft_printf("Error\nEl mapa no es rectangular.\n");
		return (1);
	}
	return (0);
}

int	error_fd(void)
{
	ft_printf("Error\nNo se pudo abrir el archivo\n");
	return (1);
}

void	ft_collect_materia(t_window *window, int player_pos)
{
	window->map->base_map[player_pos] = '0';
	--window->map->materias;
}
