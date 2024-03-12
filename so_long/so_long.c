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

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img;
	int width;
	int height;
	char *path;
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);

	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(void)
{
	t_data data;
	int w;
	int h;

	w = 50;
	h = 50;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);

	// Register key release hook
	mlx_key_hook(data.win_ptr, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, 17, 0, &on_destroy, &data);

	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "./background.xpm", &w, &h);

	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Hola Estefania! :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 600, 400);
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
