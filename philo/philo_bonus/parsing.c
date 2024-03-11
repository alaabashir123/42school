/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:24:36 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 15:01:49 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			error_exit(5, NULL);
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				error_exit(5, NULL);
		}
		i++;
	}
}

void	check_args_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' ')
				error_exit(6, NULL);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j
				- 1] != ' ' && j != 0)
				error_exit(6, NULL);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (argv[i][j + 1] == '\0' || ft_isdigit(argv[i][j + 1]) == 0)
					error_exit(6, NULL);
			j++;
		}
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	check_args_empty(argc, argv);
	check_args_char(argc, argv);
}

int	check_input(int argc, char **argv)
{
	int		j;

	j = 2;
	if (argc != 5 && argc != 6)
		error_exit(1, NULL);
	check_args(argc, argv);
	if (ft_atol(argv[1]) < 1)
		error_exit(2, NULL);
	while (j < argc)
	{
		if (ft_atol(argv[j]) < 0)
			error_exit(6, NULL);
		j++;
	}
	return (0);
}
