/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:31:32 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/23 18:54:41 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_init_pipex(t_pipex *pipex)
{
    pipex->infile_fd = -1;
    pipex->outfile_fd = -1;
    pipex->invalid_infile = false;
    pipex->paths = NULL;
    pipex->cmds = NULL;
    pipex->cmd_count = 0;
}