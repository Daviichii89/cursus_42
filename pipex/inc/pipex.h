/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:59:08 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/23 18:53:46 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	bool	invalid_infile;
	char	**paths;
	char	**cmds;
	int		cmd_count;
}	t_pipex;

bool	ft_check_args(t_pipex *pipex, int argc, char **argv);
bool	ft_parser_cmds(t_pipex *pipex, int argc, char **argv, char **envp);