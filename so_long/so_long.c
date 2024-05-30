/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:23:50 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/30 16:31:08 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_window *window)
{
	if (window)
		mlx_destroy_window(window->mlx_ptr, window->window_ptr);
	exit(1);
}

static int	key_press(int key, t_window *window)
{
	if (key == 53)
	{
		if (window->window_ptr)
			mlx_destroy_window(window->mlx_ptr, window->window_ptr);
		free(window->mlx_ptr);
		exit(1);
	}
	if (key == 13)
		move_w(window);
	if (key == 0)
		move_a(window);
	if (key == 1)
		move_s(window);
	if (key == 2)
		move_d(window);
	render_map(window);
	return (0);
}

static int	check_args_error(int argc)
{
	if (argc == 1)
		perror("Error\nDebes introducir un mapa válido.\n");
	if (argc > 2)
		perror("Error\nCantidad de argumentos no válidos.\n");
	exit(1);
}

static t_window	create_window(int width, int height)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
	{
		perror("Error\nFallo al iniciar la mlx\n");
		exit(1);
	}
	window.width = width;
	window.height = height;
	window.window_ptr = mlx_new_window(window.mlx_ptr, window.width,
			window.height, "Yuffie, la cazadora de materias.");
	if (!window.window_ptr)
	{
		perror("Error\nFallo al crear la ventana\n");
		exit(1);
	}
	return (window);
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_map		map;

	if (argc == 1 || argc > 2)
		check_args_error(argc);
	map.filename = argv[1];
	map.base_map = (char *)malloc(1 * sizeof(char));
	map.base_map[0] = '\0';
	if (check_map(&map))
		return (1);
	window = create_window(map.width, map.height);
	if (init_sprites(&window))
	{
		mlx_destroy_window(window.mlx_ptr, window.window_ptr);
		exit (1);
	}
	window.map = &map;
	window.player.render = window.player.down;
	window.movements = 0;
	render_map(&window);
	mlx_key_hook(window.window_ptr, key_press, &window);
	mlx_hook(window.window_ptr, 17, 0, exit_program, 0);
	mlx_loop(window.mlx_ptr);
	return (0);
}
