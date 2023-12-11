/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:36 by alaa              #+#    #+#             */
/*   Updated: 2023/10/04 15:54:30 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_parse
{
	bool	is_here_doc;
	bool	is_error_file;
	bool	is_error;
}			t_parse;

typedef struct s_pipex
{
	int		nb_args;
	int		fd_in;
	int		fd_out;
	char	*infile;
	char	*outfile;
	int		*pid;
	char	**path;
	char	**cmds;
	char	***args;
	char	**envp;
	t_parse	parse;
}			t_pipex;

void	ft_parse_args(int argc, char **argv, t_pipex *pipex);
void	ft_here_doc(t_pipex *pipex, char **argv);
void	ft_parse_pipes(t_pipex *pipex, char **argv);
void	ft_exec_pipes(t_pipex *pipex);
void	ft_free_pipex(t_pipex *pipex);
void	checker(int condition, char *str, int flag, t_pipex *pipex);
void	ft_free(char **str);
void	ft_free_3d(t_pipex *pipex);
int		ft_strcmp(const char *s1, const char *s2);
int		is_invalid_args(char *str);

#endif
