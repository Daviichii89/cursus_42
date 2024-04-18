#include "../so_long.h"

int check_exit(t_list *data, char letter)
{
    if (letter == 'E' && data->consumible == 0)
    {
        write(1, "Has ganado!\n", 12);
        ft_free(data);
    }
    if (letter == 'E' && data->consumible != 0)
    {
        write(1, "Necesitas recoger todos las materias!\n", 38);
        return (1);
    }
    else
        return (0);
}
