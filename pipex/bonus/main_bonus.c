/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonuc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:00:17 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 11:34:19 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_check(int argc)
{
	if (argc < 4)
	{
		ft_putstr_fd("usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	init_check(argc);
	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	checker(!pipex, "malloc error\n", 0, NULL);
	pipex->envp = envp;
	ft_parse_args(argc, argv, pipex);
	ft_here_doc(pipex, argv);
	ft_parse_pipes(pipex, argv);
	ft_exec_pipes(pipex);
	ft_free_pipex(pipex);
}
