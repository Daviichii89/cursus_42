#include "so_long.h"

static int key_press(int key, t_window *window)
{
	if (key == 53)
	{
		mlx_destroy_window(window->mlx_ptr, window->window_ptr);
		exit(1);
	}
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		printf("Movimiento\n");
	else
		printf("Using the following key for movement:\n\t\t     ^\n\t\t     |\n\t\t     W\n\t\t<- A S D ->\n");
	return (0);
}

static int check_args_error(int argc)
{
	if (argc == 1)
		ft_printf("Error\n");
	if (argc > 2)
		ft_printf("Error\n");
	exit(1);
}

static t_window create_window(int width, int height, char *str)
{
	t_window window;

	ft_printf("Creando ventana...\n");
	ft_printf("Ancho: %d\n", width);
	ft_printf("Alto: %d\n", height);
	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
	{
		ft_printf("Error\nFallo al iniciar la mlx\n");
		exit(1);
	}
	window.window_ptr = mlx_new_window(window.mlx_ptr, window.width, window.height, str);
	if (!window.window_ptr)
	{
		ft_printf("Error\nFallo al crear la ventana\n");
		exit(1);
	}
	window.width = width;
	window.height = height;
	return (window);
}

int main(int argc, char **argv)
{
	t_window window;
	t_map map;

	if (argc == 1 || argc > 2)
		check_args_error(argc);
	ft_printf("Iniciando juego...\n");
	map.filename = argv[1];
	map.base_map = (char *)malloc(1 * sizeof(char));
	map.base_map[0] = '\0';
	if (check_map(&map))
		return (1);
	ft_printf("\nMapa validado\n");
	// ft_printf("Archivo leido correctamente\n");
	window = create_window(map.width, map.height, "so_long");
	ft_printf("Ventana creada\n");
	if (init_sprites(&window))
		return (1);
	window.map = &map;
	ft_printf("Map render\n");
	window.player.render = window.player.down;
	ft_printf("Player render\n");
	window.movements = 0;
	ft_printf("Movimientos: %d\n", window.movements);
	render_map(&window);
	ft_printf("Mapa renderizado\n");
	mlx_key_hook(window.window_ptr, key_press, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
