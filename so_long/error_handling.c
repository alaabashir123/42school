/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:36:47 by abashir           #+#    #+#             */
/*   Updated: 2023/09/07 10:17:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handling(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	if (error == 2)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	if (error == 3)
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
	if (error == 4)
		ft_putstr_fd("Error\nFile(s) empty/not found or corrupted\n", 2);
	if (error == 5)
		ft_putstr_fd("Error\nMap has invalid no. of exit/collectible/start\n", 2);
	if (error == 6)
		ft_putstr_fd("Error\nDynamic allocation failed\n", 2);
	if (error == 7)
		ft_putstr_fd("Error\nPlayer can't reach collectible or exit\n", 2);
	if (error == 8)
		ft_putstr_fd("Error\nProblem in initializing the game\n", 2);
	if (error == 9)
		ft_putstr_fd("Error\nProblem in creating images\n", 2);
	if (error == 10)
		ft_putstr_fd("Error\nMap has invalid characters\n", 2);
	if (error == 11)
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
	if (error == 12)
		ft_putstr_fd("Error\nMap is not closed\n", 2);
	exit(1);
}

void	error_handling_free(int error, char **map)
{
	ft_free_arr(map);
	error_handling(error);
}

void	open_file(char *path)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd < 0 || read(fd, &buf, 1) < 1)
		error_handling(4);
	close(fd);
}

void	ft_check_files(int argc, char **argv)
{
	if (argc != 2)
		error_handling(1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		error_handling(3);
	open_file(argv[1]);
	open_file(P_PATH);
	open_file(E_PATH);
	open_file(C_PATH);
	open_file(W_PATH);
	open_file(S_PATH);
}
