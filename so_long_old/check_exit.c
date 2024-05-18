#include "so_long.h"

int check_exit(t_list *data, char letter)
{
    if (letter == 'E' && data->consumible == 0)
    {
        write(1, "Congrats, you win 🥳🏆\n", 27);
        ft_free(data);
    }
    if (letter == 'E' && data->consumible != 0)
    {
        write(1, "Necesitas recoger todos los consumibles!\n", 41);
        return (1);
    }
    else
        return (0);
}