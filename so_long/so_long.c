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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned char byte;

int encode_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	int color;
} t_data;

// int handle_input(int keycode, t_data *data)
// {
// 	if (keycode == 53)
// 	{
// 		printf("The %d key (ESC) was pressed\n", keycode);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	printf("The %d key has been pressed\n", keycode);
// 	return (0);
// }

// int button_press(int button, int x, int y, t_data *data)
// {
// 	if (button == 1)
// 		printf("The left button was pressed at (%d,%d)!\n", x, y);
// 	else if (button == 2)
// 		printf("The right button was pressed at (%d,%d)!\n", x, y);
// 	else if (button == 3)
// 		printf("The middle button was pressed at (%d,%d)!\n", x, y);

// 	return (0);
// }

// int fkey(int keycode, t_data *data)
// {
// 	printf("The %d key has been pressed\n", keycode);
// 	sleep(1);
// 	return (1);
// }

// int change_color(t_data *data)
// {
// 	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, data->color, "Cambiando el color");
// 	if (data->color == 0xFF0000)
// 		data->color = 0x00FF00;
// 	else if (data->color == 0x00FF00)
// 		data->color = 0x0000FF;
// 	else
// 		data->color = 0xFF0000;
// 	return (0);
// }
void color_screen(t_data *data, int color)
{
	int x;
	int y;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

int f(int keycode, t_data *data)
{
	if (keycode == 5)
	{
		color_screen(data, 0x00FF00);
	}
	else if (keycode == 11)
	{
		color_screen(data, 0x0000FF);
	}
	else if (keycode == 15)
	{
		color_screen(data, 0xFF0000);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (1);
}

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

int init_data(t_list *data, char *map)
{
	check_map_extension(map);
	read_map(map, data);
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
