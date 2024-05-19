/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:19:01 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/19 11:48:55 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_check_path
{
	int	materias;
	int	exit;
	int	valid;
	int	*visited;
}	t_chpath;

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*render;
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_background
{
	void	*bush;
	void	*collectible;
	void	*imgfloor;
	void	*imgexit;
	int		width;
	int		height;
}	t_background;

typedef struct s_map
{
	char		*filename;
	char		*base_map;
	int			fd;
	int			x;
	int			y;
	int			width;
	int			height;
	int			materias;
	char		*materias_left;
	t_chpath	chpath;
}	t_map;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*window_ptr;
	int				width;
	int				height;
	int				collectibles;
	int				movements;
	t_player		player;
	t_background	background;
	t_map			*map;
}	t_window;

int		init_sprites(t_window *window);
int		check_map(t_map *map);
int		render_map(t_window *window);
void	free_map(t_map *map);
void	move_w(t_map *map);
void	move_a(t_map *map);
void	move_s(t_map *map);
void	move_d(t_map *map);

#endif
