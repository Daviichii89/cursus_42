#include "so_long.h"

void check_start_line(t_list *data)
{
    int i;

    i = data->width_line - 2;
    while (i < ft_strlen(data->big_line))
    {
        if (data->big_line[i] == '1')
            i = i + data->width_line;
        else
            ft_error(data, 2);
    }
    i = data->width_line;
    while (i < ft_strlen(data->big_line))
    {
        if (data->big_line[i] == '1')
            i = i + data->width_line;
        else
            ft_error(data, 1);
    }
}

void check_fst_line(t_list *data)
{
    int i;
    int last;

    i = 0;
    last = ft_strlen(data->big_line) - data->width_line;
    while (i != data->width_line)
    {
        if (data->big_line[i] == '1' || data->big_line[i] == '\n')
            i++;
        else
            ft_error(data, 3);
    }
    while (last != ft_strlen(data->big_line))
    {
        if (data->big_line[last] == '1' || data->big_line[last] == '\n')
            last++;
        else
            ft_error(data, 4);
    }
    check_start_line(data);
}

void checkline(t_list *data)
{
    int i;

    i = 0;
    while (data->big_line[i])
    {
        if (data->big_line[i] != '1' && data->big_line[i] != '0' && data->big_line[i] != 'P' && data->big_line[i] != 'E' && data->big_line[i] != 'C' && data->big_line[i] != '\n')
            ft_error(data, 8);
        if (data->big_line[i] == 'P')
            data->player++;
        if (data->big_line[i] == 'E')
            data->exit++;
        if (data->big_line[i] == 'C')
            data->consumible++;
        if (data->big_line[i] == '1')
            data->wall++;
        if (data->big_line[i] == '0')
            data->floor++;
        i++;
    }
    printf("Elementos del mapa:\n\n");
    printf("Salida (E): %d\n", data->exit);
    printf("Consumible (C): %d\n", data->consumible);
    printf("Jugador (P): %d\n", data->player);
    printf("Muro (1): %d\n", data->wall);
    printf("Suelo (0): %d\n\n", data->floor);
    if (data->exit < 1 || data->consumible < 1 || data->wall < 1 || data->player != 1)
        ft_error(data, 5);
}

void check_line_break(char *line, t_list *data)
{
    int i;

    i = 0;
    data->linecontrol = 1;
    while (line[i])
    {
        if (line[i] == '\n')
            data->linecontrol = 0;
        i++;
    }
}

void read_map(char *map, t_list *data)
{
    int fd;
    char *line;

    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        write(1, "No se pudo abrir el archivo\n", 29);
        ft_free(data);
    }
    data->linecontrol = 2;
    while (data->linecontrol != 1)
    {
        data->height_line++;
        line = get_next_line(fd);
        if (!line)
            ft_error(data, 9);
        if (data->linecontrol == 2)
            data->width_line = ft_strlen(line);
        check_line_break(line, data);
        if (ft_strlen(line) + data->linecontrol != data->width_line)
            ft_error(data, 7);
        data->big_line = ft_strjoin(data->big_line, line);
        if (line)
            free(line);
    }
    printf("\nFile leido:\n\n%s\n\n", data->big_line);
    close(fd);
    check_fst_line(data);
    checkline(data);
}