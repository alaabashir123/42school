/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:32:45 by abashir           #+#    #+#             */
/*   Updated: 2023/10/04 11:34:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	read_here_doc(t_pipex *pipex, char **argv, int fd)
{
	char	*line;

	ft_putstr_fd("pipex heredoc> ", 1);
	line = get_next_line(0);
	checker(line == NULL, "here_doc is empty\n", 1, pipex);
	while (ft_strcmp(argv[2], line) && line)
	{
		ft_putstr_fd(line, fd);
		free(line);
		ft_putstr_fd("pipex heredoc> ", 1);
		line = get_next_line(0);
		checker(line == NULL, "here_doc was terminated\n", 1, pipex);
	}
	free(line);
}

void	ft_here_doc(t_pipex *pipex, char **argv)
{
	if (pipex->parse.is_here_doc)
	{
		pipex->fd_in = open("_temp_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		checker(pipex->fd_in == -1, "create file error\n", 0, pipex);
		pipex->infile = "_temp_file";
		read_here_doc(pipex, argv, pipex->fd_in);
		close(pipex->fd_in);
	}
}
