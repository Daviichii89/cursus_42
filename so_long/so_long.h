/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:19:01 by davifer2          #+#    #+#             */
/*   Updated: 2024/03/12 14:24:48 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

define	SO_LONG_H


typedef struct s_data
{
	void	*mlx_pointer;
	void	*window_pointer;
	void	*textures[5];
	t_map	*map
} t_data;
