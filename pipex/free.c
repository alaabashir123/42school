/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:20:29 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 15:40:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free_3d(t_pipex *pipex)
{
	int	i;
	int	j;

	i = -1;
	while (pipex->args[++i])
	{
		j = -1;
		while (pipex->args[i][++j])
			free(pipex->args[i][j]);
		free(pipex->args[i]);
	}
	free(pipex->args);
}

void	ft_free_pipex(t_pipex *pipex)
{
	bool	i;

	if (pipex->args)
		ft_free_3d(pipex);
	if (pipex->path)
		ft_free(pipex->path);
	if (pipex->cmds)
		ft_free(pipex->cmds);
	if (pipex->pid)
		free(pipex->pid);
	close(pipex->fd_in);
	close(pipex->fd_out);
	if (pipex->parse.is_error_file)
		unlink(pipex->infile);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	i = pipex->parse.is_error;
	free(pipex);
	if (i)
		exit(errno);
	else
		exit(EXIT_SUCCESS);
}
