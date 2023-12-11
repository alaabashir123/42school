/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:28:55 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 15:54:16 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(char *str, int flag, t_pipex *pipex)
{
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
	if (pipex->outfile)
		unlink(pipex->outfile);
	if (flag && (pipex->parse.is_here_doc || pipex->parse.is_error_file))
		unlink(pipex->infile);
	free(pipex);
	ft_putstr_fd(str, 2);
	exit(errno);
}

void	checker(int condition, char *str, int flag, t_pipex *pipex)
{
	if (condition)
		error_exit(str, flag, pipex);
}
