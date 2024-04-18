#include "../so_long.h"

int ft_free(t_list *mlx)
{
    if (mlx)
        free(mlx);
    exit(1);
}
