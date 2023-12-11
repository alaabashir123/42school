/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:33:23 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 15:19:39 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	count_args(t_pipex *pipex, int i, int argc, char **argv)
{
	int	nb_args;

	nb_args = 0;
	while (i < argc - 1)
	{
		if (!is_invalid_args(argv[i]))
			nb_args++;
		else
		{
			ft_putstr_fd(argv[i], 2);
			ft_putendl_fd(" :command not found", 2);
		}
		i++;
	}
	checker(nb_args == 0, "", 0, pipex);
	pipex->nb_args = nb_args;
	pipex->outfile = argv[argc - 1];
}

static void	create_args(t_pipex *pipex, int j, char **argv)
{
	int	i;

	i = 0;
	pipex->args = ft_calloc(sizeof(char **), (pipex->nb_args + 1));
	checker(!pipex->args, "malloc error \n", 0, pipex);
	while (i < pipex->nb_args)
	{
		if (!is_invalid_args(argv[j]))
		{
			pipex->args[i] = ft_split(argv[j], ' ');
			checker(!pipex->args[i], "malloc error\n", 0, pipex);
			i++;
		}
		j++;
	}
	pipex->args[i] = NULL;
}

void	ft_parse_args(int argc, char **argv, t_pipex *pipex)
{
	int		i;
	int		fd;

	i = 2;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		pipex->parse.is_error_file = true;
		perror("error");
		i++;
	}
	else
		close(fd);
	count_args(pipex, i, argc, argv);
	create_args(pipex, i, argv);
}
