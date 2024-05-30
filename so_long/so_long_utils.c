/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:27:44 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/30 18:17:38 by davifer2         ###   ########.fr       */
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
	if (!filename)
		return (1);
	if (i > 5 && filename[i - 4] == '.' && filename[i - 3] != 'b'
		&& filename[i - 2] != 'e' && filename[i - 1] != 'r')
	{
		perror("Error\nExtension del archivo inválido\n");
		return (1);
	}
	return (0);
}

int	error_map_size(char *line, t_map *map, int error_code)
{
	(void)line;
	if (error_code == 1)
	{
		perror("Error\nEl mapa no es rectangular error 1.\n");
		close(map->fd);
		exit (1);
	}
	else if (error_code == 2)
	{
		ft_printf("Error\nNo se pudo abrir el archivo\n");
		return (1);
	}
	else if (error_code == 3)
	{
		perror("Error\nEl mapa no es rectangular error 3.\n");
		exit (1);
	}
	return (0);
}

int	error_fd(void)
{
	perror("Error\nNo se pudo abrir el archivo\n");
	return (1);
}

void	ft_collect_materia(t_window *window, int player_pos)
{
	window->map->base_map[player_pos] = '0';
	window->map->materias--;
}
