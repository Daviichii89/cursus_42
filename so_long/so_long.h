/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:19:01 by davifer2          #+#    #+#             */
/*   Updated: 2024/05/30 19:53:19 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/get_next_line.h"

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
int		check_map_extension(char *filename);
int		find_player_position(t_map *map);
int		error_map_size(char *line, t_map *map, int error_code);
int		error_fd(void);
void	free_map(t_map *map);
int		exit_program(t_window *window);
void	ft_collect_materia(t_window *window, int player_pos);
void	move_w(t_window *window);
void	move_a(t_window *window);
void	move_s(t_window *window);
void	move_d(t_window *window);

#endif
