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

#define WIN_WIDTH 600
#define WIN_HEIGHT 400
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define BLUE_PIXEL 0x0000FF
#define WHITE_PIXEL 0xFFFFFF

// typedef unsigned char byte;

// int encode_rgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
} t_data;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
} t_rect;

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
void img_pixel_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	int i;

	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
// void color_screen(t_data *data, int color)
// {
// 	for (int y = 0; y < 400; ++y)
// 	{
// 		for (int x = 0; x < 600; ++x)
// 		{
// 			img_pixel_put(&data->img, x, y, color);
// 		}
// 	}
// }

// int f(int keycode, t_data *data)
// {
// 	if (keycode == 15)
// 	{
// 		color_screen(data, encode_rgb(255, 0, 0));
// 	}
// 	else if (keycode == 5)
// 	{
// 		color_screen(data, encode_rgb(0, 0xff, 0));
// 	}
// 	else if (keycode == 11)
// 	{
// 		color_screen(data, encode_rgb(0, 0, 0xff));
// 	}
// 	else if (keycode == 53)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
// 	return (0);
// }

int handle_keypress(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(1);
	}
	return (0);
}

int render_rect(t_img *img, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void render_background(t_img *img, int color)
{
	int i;
	int j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pixel_put(img, j++, i, color);
		++i;
	}
}

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WIN_WIDTH - 100, WIN_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);

	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	// data.img.img_ptr = mlx_new_image(data.mlx_ptr, 600, 400);
	// data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	// mlx_key_hook(data.win_ptr, handle_input, &data);
	// mlx_hook(data.win_ptr, 2, 1L << 0, &button_press, &data);
	// mlx_key_hook(data.win_ptr, fkey, &data);
	// mlx_loop_hook(data.mlx_ptr, change_color, &data);

	// printf("Line length: %d <-> SIDE_LEN %d\n"
	// 	   "bpp %d\n"
	// 	   "endian %d\n",
	// 	   data.img.line_length, 600, data.img.bits_per_pixel, data.img.endian);
	// mlx_key_hook(data.win_ptr, f, &data);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

// keycode 5 = G
// keycode 11 = B
// keycode 15 = R
// keycode 53 = ESC