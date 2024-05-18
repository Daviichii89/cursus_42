#include "so_long.h"

// static void render_background(t_window *window)
// {
//     int x;
//     int y;

//     y = 0;
//     while (y < window->map->y)
//     {
//         x = 0;
//         while (x < window->map->x)
//         {
//             if (window->map->base_map[y * window->map->x + x] == '1')
//                 mlx_put_image_to_window(window->mlx_ptr, window->window_ptr, window->background.bush, x * 50, y * 50);
//             else if (window->map->base_map[y * window->map->x + x] == 'E')
//                 mlx_put_image_to_window(window->mlx_ptr, window->window_ptr, window->background.imgexit, x * 50, y * 50);
//             else if (window->map->base_map[y * window->map->x + x] == '0')
//                 mlx_put_image_to_window(window->mlx_ptr, window->window_ptr, window->background.imgfloor, x * 50, y * 50);
//             else if (window->map->base_map[y * window->map->x + x] == 'C')
//                 mlx_put_image_to_window(window->mlx_ptr, window->window_ptr, window->background.collectible, x * 50, y * 50);
//             else if (window->map->base_map[y * window->map->x + x] == 'P')
//             {
//                 window->player.pos_x = x * 50;
//                 window->player.pos_y = y * 50;
//             }

//             ++x;
//         }

//         ++y;
//     }
// }

static void render_specials(t_window *window, char *map_pos, int x, int y)
{
    if (*map_pos == 'C')
        mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
                                window->background.collectible, x * 50, y * 50);
    if (*map_pos == '1')
        mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
                                window->background.bush, x * 50, y * 50);
    if (*map_pos == 'E')
        mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
                                window->background.imgexit, x * 50, y * 50);
    if (*map_pos == 'P')
    {
        window->player.pos_x = x * 50;
        window->player.pos_y = y * 50;
        *map_pos = '0';
    }
}

static void render_background(t_window *window)
{
    int y;
    int x;
    int i;
    char *map_pos;

    y = 0;
    i = 0;
    while (y < window->map->y)
    {
        x = 0;
        while (x < window->map->x)
        {
            map_pos = &window->map->base_map[i];
            if (ft_strchr("0PC", *map_pos))
                mlx_put_image_to_window(window->mlx_ptr, window->window_ptr,
                                        window->background.imgfloor, x * 50, y * 50);
            if (ft_strchr("C1EP", *map_pos))
                render_specials(window, map_pos, x, y);
            ++x;
            ++i;
        }
        ++y;
    }
}

int render_map(t_window *window)
{
    char *materias;
    char *movements;

    materias = ft_itoa(window->map->materias);
    movements = ft_itoa(window->movements);
    ft_printf("Materias: %s\nMovimientos: %s\n", materias, movements);
    render_background(window);
    ft_printf("Background render\n");
    ft_printf("x: %d, y: %d\n", window->player.pos_x, window->player.pos_y);
    mlx_put_image_to_window(window->mlx_ptr, window->window_ptr, window->player.down, window->player.pos_x, window->player.pos_y);
    ft_printf("Player render\n");
    free(materias);
    free(movements);
    return (0);
}