/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:35:22 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/23 18:54:27 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool  ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 5)
		return (false);
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		pipex->invalid_infile = true;
		return (false);
	}
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd == -1)
		return (false);
	pipex->cmd_count = argc - 3;
	return (true);
}

char	*ft_get_path(char *cmd, char **envp)
{
	
}

bool  ft_parser_cmds(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	i;
	char	**cmd;

	pipex->paths = ft_calloc(sizeof(char *), pipex->cmd_count);
	if (!pipex->paths)
		return (false);
	i = 1;
	while (i < argc - 2)
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
		{
			ft_free_split(pipex->paths);
			pipex->paths = NULL;
			return (false);
		}
		pipex->paths[i - 1] = ft_get_path(cmd[0], envp);
		if (!pipex->paths[i - 1])
			return (false);
		free(cmd);
		i++;
	}
}