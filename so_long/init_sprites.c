/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:36:09 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/30 16:41:43 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_sprites(t_window *window)
{
	window->background.bush = mlx_xpm_file_to_image(window->mlx_ptr,
			"sprites/bush.xpm", &(window->width), &(window->height));
	window->background.imgexit = mlx_xpm_file_to_image(window->mlx_ptr,
			"sprites/imgexit.xpm", &(window->width), &(window->height));
	window->background.imgfloor = mlx_xpm_file_to_image(window->mlx_ptr,
			"sprites/fond.xpm", &(window->width), &(window->height));
	window->background.collectible = mlx_xpm_file_to_image(window->mlx_ptr,
			"sprites/materia_azul.xpm", &(window->width), &(window->height));
	window->player.down = mlx_xpm_file_to_image(window->mlx_ptr,
			"sprites/yuffie.xpm", &(window->width), &(window->height));
	if (window->background.bush == NULL || window->background.imgexit == NULL
		|| window->background.imgfloor == NULL
		|| window->background.collectible == NULL
		|| window->player.down == NULL)
	{
		perror("Error\nNo se pudo cargar los sprites correctamente.\n");
		return (1);
	}
	return (0);
}
