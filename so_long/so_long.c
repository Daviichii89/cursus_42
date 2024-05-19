/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:23:50 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/19 11:52:06 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_press(int key, t_window *window)
{
	t_map	map;

	if (key == 53)
	{
		if (window->window_ptr)
			mlx_destroy_window(window->mlx_ptr, window->window_ptr);
		free(window->mlx_ptr);
		exit(1);
	}
	if (key == 13)
		move_w(&map);
	if (key == 0)
		move_a(&map);
	if (key == 1)
		move_s(&map);
	if (key == 2)
		move_d(&map);
	ft_printf("tecla d presionada\n");
	return (0);
}

static int	check_args_error(int argc)
{
	if (argc == 1)
		ft_printf("Error\n");
	if (argc > 2)
		ft_printf("Error\n");
	exit(1);
}

static t_window	create_window(int width, int height)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
	{
		ft_printf("Error\nFallo al iniciar la mlx\n");
		exit(1);
	}
	window.width = width;
	window.height = height;
	window.window_ptr = mlx_new_window(window.mlx_ptr, window.width,
			window.height, "so_long");
	if (!window.window_ptr)
	{
		ft_printf("Error\nFallo al crear la ventana\n");
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
		return (1);
	window.map = &map;
	window.player.render = window.player.down;
	window.movements = 0;
	ft_printf("Movimientos: %d\n", window.movements);
	render_map(&window);
	ft_printf("Mapa renderizado\n");
	mlx_key_hook(window.window_ptr, key_press, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
