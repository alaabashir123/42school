/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:06 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 13:16:27 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_set_path(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_substr(pipex->envp[i], 5, ft_strlen(pipex->envp[i]) - 5);
			checker(!tmp, "malloc\n", 1, pipex);
			pipex->path = ft_split(tmp, ':');
			free(tmp);
			checker(!pipex->path, "malloc\n", 1, pipex);
			return ;
		}
		i++;
	}
	checker(!pipex->path, "envp paths not found\n", 1, pipex);
}

static void	ft_set_cmds(t_pipex *pipex, int j)
{
	int		i;
	char	*temp;

	i = -1;
	while (pipex->path[++i])
	{
		if (pipex->args[j][0][0] == '/' && access(pipex->args[j][0],
			F_OK) == 0 && access(pipex->args[j][0], X_OK) == 0)
		{
			pipex->cmds[j] = ft_strdup(pipex->args[j][0]);
			checker(!pipex->cmds[j], "malloc\n", 1, pipex);
			return ;
		}
		temp = ft_strjoin(pipex->path[i], "/", pipex->args[j][0]);
		checker(!temp, "malloc\n", 1, pipex);
		if (access(temp, F_OK) == 0 && access(temp, X_OK) == 0)
		{
			pipex->cmds[j] = ft_strdup(temp);
			free(temp);
			checker(!pipex->cmds[j], "malloc\n", 1, pipex);
			return ;
		}
		free(temp);
	}
}

static void	ft_parse_cmds(t_pipex *pipex)
{
	int		j;

	j = 0;
	pipex->cmds = ft_calloc((pipex->nb_args + 1), sizeof(char *));
	checker(!pipex->cmds, "malloc\n", 1, pipex);
	while (pipex->args[j])
	{
		ft_set_cmds(pipex, j);
		if (!pipex->cmds[j])
		{
			pipex->cmds[j] = ft_strdup(pipex->args[j][0]);
			pipex->parse.is_error = true;
		}
		j++;
	}
	pipex->cmds[j] = NULL;
}

static void	ft_set_files(t_pipex *pipex, char **argv)
{
	if (pipex->parse.is_here_doc)
	{
		pipex->fd_in = open("_temp_file", O_RDONLY);
		pipex->fd_out = open(pipex->outfile, O_WRONLY | O_APPEND);
		if (pipex->fd_out == -1)
			pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT, 0777);
		return ;
	}
	else if (pipex->parse.is_error_file)
	{
		pipex->fd_in = open("_temp_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		checker(pipex->fd_in == -1, "open file error\n", 0, pipex);
		close(pipex->fd_in);
		pipex->fd_in = open("_temp_file", O_RDONLY);
		checker(pipex->fd_in == -1, "open file error\n", 1, pipex);
		pipex->infile = "_temp_file";
	}
	else
	{
		pipex->fd_in = open(argv[1], O_RDONLY);
		checker(pipex->fd_in == -1, "open file error\n", 0, pipex);
		pipex->infile = argv[1];
	}
	pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	checker(pipex->fd_out == -1, "create file error\n", 1, pipex);
}

void	ft_parse_pipes(t_pipex *pipex, char **argv)
{
	ft_set_files(pipex, argv);
	ft_set_path(pipex);
	ft_parse_cmds(pipex);
}
