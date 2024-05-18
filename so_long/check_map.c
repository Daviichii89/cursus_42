#include "so_long.h"

static int check_map_extension(char *filename)
{
	int i;

	i = ft_strlen(filename);
	if (i > 2 && filename[i - 4] != '.' && filename[i - 3] != 'b' && filename[i - 2] != 'e' && filename[i - 1] != 'r')
	{
		ft_printf("Error\nExtension del archivo invalida\n");
		return (1);
	}
	return (0);
}

static int check_map_size(t_map *map)
{
	char *line;

	map->fd = open(map->filename, O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("Error\nNo se pudo abrir el archivo\n");
		return (1);
	}
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
		{
			ft_printf("Error\nEl mapa no es rectangular.\n");
			close(map->fd);
			free(line);
			return (1);
		}
	}
	close(map->fd);
	if (map->x <= map->y)
	{
		ft_printf("Error\nEl mapa no es rectangular.\n");
		return (1);
	}
	map->width = map->x * 50;
	map->height = map->y * 50;
	return (0);
}

int check_map_walls(t_map *map)
{
	int i;

	i = 0;
	while (map->base_map[i])
	{
		if (map->base_map[i] != '1' && map->base_map[i] != '0' && map->base_map[i] != 'P' && map->base_map[i] != 'E' && map->base_map[i] != 'C')
		{
			ft_printf("Error\n");
			return (1);
		}
		++i;
	}
	return (0);
}

int check_valid_map(t_map *map, int pos_player)
{
	int i;
	// int j;

	i = 0;
	// j = 0;
	t_map *tmp;

	tmp = map;
	while (tmp->base_map[i])
	{
		if (tmp->base_map[i] == 'P')
		{
			if (i != pos_player)
			{
				ft_printf("Error\n");
				return (0);
			}
		}
		if (tmp->base_map[i] == 'E')
			++map->chpath.exit;
		if (tmp->base_map[i] == 'C')
			++tmp->chpath.materias;
		++i;
	}
	if (tmp->chpath.exit != 1 || tmp->chpath.materias < 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int validate_sprites(t_map *map)
{
	int i;
	int exit;
	int player;
	char character;

	i = 0;
	exit = 0;
	player = 0;
	map->materias = 0;
	while (map->base_map[i])
	{
		character = map->base_map[i];
		if (character == 'P')
			++player;
		if (character == 'E')
			++exit;
		if (character == 'C')
			++map->materias;
		++i;
	}
	if (player != 1 || exit != 1 || map->materias < 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

static int find_player_position(t_map *map)
{
	int i;

	i = 0;
	while (map->base_map[i] != 'P')
		++i;
	return (i);
}

int check_map(t_map *map)
{
	int pos_player;

	if (check_map_extension(map->filename))
		return (1);
	if (check_map_size(map) || check_map_walls(map) || validate_sprites(map))
	{
		free(map->base_map);
		return (1);
	}
	pos_player = find_player_position(map);
	ft_printf("\nPosicion del jugador: %d.\n", pos_player);
	map->chpath.valid = 0;
	map->chpath.materias = 0;
	map->chpath.exit = 0;
	map->chpath.visited = ft_calloc(map->x * map->y, sizeof(int));
	ft_printf("\nchpath inicializado.\n");
	if (!(check_valid_map(map, pos_player)))
	{
		//free_map(&map);
		free(map->chpath.visited);
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
