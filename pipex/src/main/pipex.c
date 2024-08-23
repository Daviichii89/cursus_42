/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:04:29 by davifer2          #+#    #+#             */
/*   Updated: 2024/08/23 18:55:10 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	ft_init_pipex(pipex);
	if (!ft_check_args(pipex, argc, argv))
	{
		ft_cleanup(pipex);
		return (EXIT_FAILURE);
	}
	if (!ft_parser_cmds(pipex, argc, argv, envp))
	{
		ft_cleanup(pipex);
		return (EXIT_FAILURE);
	}
	// ft_parser_args();
	// while (cmds)
	ft_exec_cmds(argc, argv);
	// ft_clean();
}

// https://reactive.so/post/42-a-comprehensive-guide-to-pipex/
// https://github.com/herbievine/42/blob/main/pipex/parse.c
// https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103