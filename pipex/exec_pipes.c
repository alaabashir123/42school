/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:25 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 15:50:04 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_set_fork(int fd[2], t_pipex *pipex, int i)
{
	checker(pipe(fd) == -1, "cannot create pipe\n", 1, pipex);
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		checker(pipex->pid[i] == -1, "cannot create fork\n", 1, pipex);
	}
}

static void	ft_set_dup2(t_pipex *pipex, int i, int fd[2])
{
	if (i == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		close(pipex->fd_in);
	}
	if (pipex->cmds[i + 1] != NULL)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	else if (pipex->cmds[i + 1] == NULL)
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		close(pipex->fd_out);
	}
}

static void	ft_exec(t_pipex *pipex, int i, char *cmd)
{
	int	fd[2];

	ft_set_fork(fd, pipex, i);
	if (pipex->pid[i] == 0)
	{
		close(fd[0]);
		ft_set_dup2(pipex, i, fd);
		if (execve(cmd, pipex->args[i], pipex->envp) == -1)
		{
			ft_putstr_fd(cmd, 2);
			ft_putendl_fd(" :command not found", 2);
			close(fd[1]);
			pipex->parse.is_error = true;
			ft_free_pipex(pipex);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	ft_exec_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->pid = (int *)ft_calloc((pipex->nb_args), sizeof(int));
	checker(!pipex->pid, "malloc\n", 1, pipex);
	while (pipex->cmds[++i])
		ft_exec(pipex, i, pipex->cmds[i]);
	while (i--)
		waitpid(pipex->pid[i], NULL, 0);
}
