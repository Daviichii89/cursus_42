#include "so_long.h"

void ft_error2(t_list *mlx, int num)
{
    if (num == 8)
        write(1, "►El mapa contiene caracteres erroneos.\n", 41);
    if (num == 9)
        write(1, "►El mapa no es rectangular\n", 29);
    printf("%p\n", mlx);
}

void ft_error(t_list *mlx, int num)
{
    write(1, "❌ERROR❌\n", 12);
    if (num > 7)
        ft_error2(mlx, num);
    if (num == 1)
        write(1, "►En el principio de linea no hay pared.🧱\n", 46);
    if (num == 2)
        write(1, "►En el final de linea no hay pared.🧱\n", 42);
    if (num == 3)
        write(1, "►En la primera linea no hay pared.🧱\n", 41);
    if (num == 4)
        write(1, "►En la ultima linea no hay pared.🧱\n", 40);
    if (mlx->consumible < 1 && num == 5)
        write(1, "►No hay consumibles!\n", 21);
    if (mlx->player != 1 && num == 5)
        write(1, "►El mapa solo debe tener un personaje. 🚶🏻‍♂️\n", 59);
    if (mlx->exit < 1 && num == 5)
        write(1, "►El mapa debe contener una salida. \n", 38);
    if (num == 6)
        write(1, "►El fichero no tiene la extension correcta.\n", 46);
    if (num == 7)
        write(1, "►El mapa no es rectangular.\n", 30);
    ft_free(mlx);
}