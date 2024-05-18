/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:31:55 by davifer2          #+#    #+#             */
/*   Updated: 2024/03/12 16:09:39 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx/mlx.h"

void move_w(t_list *data)
{
	int i;

	i = 0;
	while (data->big_line[i] != 'P')
	{
		printf("i: %d\n", i);
		i++;
	}
	if (data->big_line[i - data->width_line] != '1' && !check_exit(data, data->big_line[i - data->width_line]))
	{
		if (data->big_line[i - data->width_line] == 'C')
			data->consumible--;
		data->big_line[i] = '0';
		data->big_line[i - data->width_line] = 'P';
	}
	printf("Consumibles: %d\n", data->consumible);
	print_map(data);
}

int keypress(int keycode, t_list *data)
{
	static int moves;

	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		ft_free(data);
	}
	if (moves >= 0)
	{
		if (keycode == 13)
		{
			moves++;
			printf("Has presionado la W: Movimientos: %d\n", moves);
			move_w(data);
		}
		if (keycode == 0)
		{
			moves++;
			printf("Has presionado la A Movimientos: %d\n", moves);
		}
		if (keycode == 1)
		{
			moves++;
			printf("Has presionado la S Movimientos: %d\n", moves);
		}
		if (keycode == 2)
		{
			moves++;
			printf("Has presionado la D Movimientos: %d\n", moves);
		}
	}
	else
	{
		moves = 0;
		printf("Movimientos: %d\n", moves);
	}
	return (0);
}

void check_map_extension(char *map)
{
	int i;

	i = ft_strlen(map);
	if (i > 2 && map[i - 4] != '.' && map[i - 3] != 'b' && map[i - 2] != 'e' && map[i - 1] != 'r')
	{
		write(1, "Extension del mapa incorrecta\n", 30);
	}
	else
		write(1, "Extension del mapa correcta\n", 28);
}

void init_sprites(t_list *data)
{

	int width;
	int height;

	width = 50;
	height = 50;
	data->y = (ft_strlen(data->big_line) / data->width_line + 1) * 50;
	data->x = (data->width_line - 1) * 50;
	data->bush = mlx_xpm_file_to_image(data->mlx_ptr, "bush.xpm", &width, &height);
	data->imgexit = mlx_xpm_file_to_image(data->mlx_ptr, "imgexit.xpm", &width, &height);
	data->imgfloor = mlx_xpm_file_to_image(data->mlx_ptr, "fond.xpm", &width, &height);
	data->npc = mlx_xpm_file_to_image(data->mlx_ptr, "yuffie.xpm", &width, &height);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "materia_azul.xpm", &width, &height);
}

// int validate_way_to_exit(char *map, t_position player_position)
// {
// 	char **visited;

// 	visited = ft_calloc(ft_strlen(map), sizeof(char *));
// 	int x;
// 	int y;

// 	printf("Visited: %p\n", visited);
// 	x = player_position.x;
// 	y = player_position.y;
// 	printf("Player position x: %d\n", x);
// 	printf("Player position y: %d\n", y);
// 	if (map[y * ft_strlen(map) + x] == 'E')
// 	{
// 		return (1);
// 	}
// 	printf("Visited: %p\n", visited);
// 	if (map[y * ft_strlen(map) + x + 1] != '1' && !visited[y][x + 1])
// 	{
// 		visited[y][x + 1] = 1;
// 		validate_way_to_exit(map, (t_position){x + 1, y});
// 	}
// 	if (map[y * ft_strlen(map) + x - 1] != '1' && !visited[y][x - 1])
// 	{
// 		visited[y][x - 1] = 1;
// 		validate_way_to_exit(map, (t_position){x - 1, y});
// 	}
// 	if (map[(y + 1) * ft_strlen(map) + x] != '1' && !visited[y + 1][x])
// 	{
// 		visited[y + 1][x] = 1;
// 		validate_way_to_exit(map, (t_position){x, y + 1});
// 	}
// 	if (map[(y - 1) * ft_strlen(map) + x] != '1' && !visited[y - 1][x])
// 	{
// 		visited[y - 1][x] = 1;
// 		validate_way_to_exit(map, (t_position){x, y - 1});
// 	}
// 	return (0);
// }

int validate_way_to_exit(char *map, int row, int col, int width, int height)
{
	t_chmap visited;
	int index;

	index = row * width + col;
	if (visited.map[index] == 'E')
		return (1);
	visited.map[index] = 'V';
	int result = 0;
	if (row > 0 && visited.map[index - width] != '1' && visited.map[index - width] != 'V')
		result |= validate_way_to_exit(visited.map, row - 1, col, width, height);
	if (row < height - 1 && visited.map[index + width] != '1' && visited.map[index + width] != 'V')
		result |= validate_way_to_exit(visited.map, row + 1, col, width, height);
	if (col > 0 && visited.map[index - 1] != '1' && visited.map[index - 1] != 'V')
		result |= validate_way_to_exit(visited.map, row, col - 1, width, height);
	if (col < width - 1 && visited.map[index + 1] != '1' && visited.map[index + 1] != 'V')
		result |= validate_way_to_exit(visited.map, row, col + 1, width, height);
	return (result);
}

t_position find_player_position(char *map, int width, int height)
{
	t_position player_pos = {-1, -1}; // Inicializar la posición del jugador como inválida

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (map[y * width + x] == 'P')
			{
				player_pos.x = x;
				player_pos.y = y;
				return player_pos; // Devolver la posición del jugador si se encuentra
			}
		}
	}

	return player_pos;
}

int init_data(t_list *data, char *map)
{
	t_position player_position;

	if (map == NULL)
	{
		printf("Error: mapa no puede ser NULL.\n");
		return -1; // Devuelve un valor indicando un error
	}
	check_map_extension(map);
	read_map(map, data);
	printf("Width: %d\n", data->width_line);
	printf("Height: %d\n", data->height_line);
	printf("Big line: %s\n", data->big_line);
	player_position = find_player_position(data->big_line, data->width_line, data->height_line);

	printf("Player position x: %d\n", player_position.x);
	printf("Player position y: %d\n", player_position.y);
	printf("La posicion del player contiene: %c\n", data->big_line[player_position.y * data->width_line + player_position.x]);
	if (validate_way_to_exit(data->big_line, player_position.y, player_position.x, data->width_line, data->height_line))
	{
		write(1, "Hay salida\n", 11);
	}
	else
	{
		write(1, "No hay salida\n", 14);
	}
	//  if (validate_way_to_exit(data->big_line, player_position.x, player_position.y))
	//  {
	//  	write(1, "Hay salida\n", 11);
	//  }
	//  else
	//  {
	//  	write(1, "No hay salida\n", 14);
	//  }
	init_sprites(data);
	data->window_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "so_long");
	print_map(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_list *data;
	if (argc != 2)
	{
		write(1, "Número de argumentos incorrecto.\n", 33);
		return (0);
	}
	data = ft_calloc(1, sizeof(t_list));
	if (!data)
	{
		write(1, "Error\nNo se pudo inicializar mlx\n", 34);
		return (0);
	}

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		write(1, "Error\nNo se pudo inicializar mlx\n", 34);
		return (1);
	}
	init_data(data, argv[1]);
	if (data->window_ptr == NULL)
	{
		write(1, "Error\nNo se pudo abrir la ventana\n", 34);
		free(data->window_ptr);
		return (1);
	}

	mlx_key_hook(data->window_ptr, keypress, &data);
	// mlx_hook(data->window_ptr, 17, 0, keypress, &data);
	mlx_loop(data->mlx_ptr);
	ft_free(data);
	return (0);
}

// 1. Chequear los errores y leaks de memoria
//	- numero de argumentos
// 	- malloc estructuras juego
//	- extension del mapa
//	- mlx_init()
//	- abrir el archivo y lectura del mapa: open() close() get_next_line()
//	- si el mapa es valido (es rectangular)
//	- si hay un jugador, si hay un coleccionable, si hay una salida.
//	- si hay un muro alrededor del mapa
//	- que todos los sprites esten bien: mlx_new_window() mlx_xpm_file_to_image()
//	- al salir del juego:
//	- window: mlx_destroy_window()
//	- mlx: mlx_destroy_display + free()
//	- sprites: mlx_destroy_image()
//	- estructuras: free()
// 2. Inicializar las estructuras del juego
//	- NULL 0 o mlx_init()?
// 3. Dibujar el mapa
//	- analizar el mapa y dibujar los sprites correspondientes en la ventana: mlx_put_image_to_window()
// 4. Interacciones de teclado
//	- mlx_key_hook()
// 5. Insertar el código para
//	- autorización para avanzar personaje o no, y acción si ok
// 6. bonus
//	- contar movimientos: mlx_string_put()
// 7. aparecen imágenes en un bucle
//	-mlx_loop()
//	- mlx_hook(), te permite insertar una función para cerrar la ventana con la cruz
