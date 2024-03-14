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

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "so_long");
	data.color = 0xFF0000;
	if (!data.win_ptr)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	// mlx_key_hook(data.win_ptr, handle_input, &data);
	// mlx_hook(data.win_ptr, 2, 1L << 0, &button_press, &data);
	// mlx_key_hook(data.win_ptr, fkey, &data);
	// mlx_loop_hook(data.mlx_ptr, change_color, &data);
	mlx_key_hook(data.win_ptr, f, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

// keycode 5 = G
// keycode 11 = B
// keycode 15 = R
// keycode 53 = ESC