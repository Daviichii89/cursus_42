#include "../so_long.h"
#include "../mlx/mlx.h"

void calc_xy(char c, int i, t_list *data)
{
    int x;
    int y;

    y = (i / data->width_line) * 50;
    x = (i % data->width_line) * 50;

    if (c == '1')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->bush, x, y);
    }
    if (c == '0')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->imgfloor, x, y);
    }
    if (c == 'P')
    {
        data->player_position.y = data->big_line[i];
        printf("Player position: %c\n", data->player_position.y);
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->npc, x, y);
    }
    if (c == 'E')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->imgexit, x, y);
    }
    if (c == 'C')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->collectible, x, y);
    }
}

void print_map(t_list *data)
{
    int i;
    printf("Hola entro a print_map\n");
    i = 0;
    while (data->big_line[i])
    {
        if (data->big_line[i] == '\n')
            i++;
        if (data->big_line[i] != '1' && data->big_line[i] != '0' && data->big_line[i] != 'P' && data->big_line[i] != 'E' && data->big_line[i] != 'C')
            exit(0);
        if (data->big_line[i] == '1')
            calc_xy('1', i, data);
        if (data->big_line[i] == '0')
            calc_xy('0', i, data);
        if (data->big_line[i] == 'P')
            calc_xy('P', i, data);
        if (data->big_line[i] == 'E')
            calc_xy('E', i, data);
        if (data->big_line[i] == 'C')
            calc_xy('C', i, data);
        i++;
    }
}
