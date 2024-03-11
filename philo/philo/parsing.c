/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:24:36 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 16:02:10 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (error_exit(5, NULL), 1);
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				return (error_exit(5, NULL), 1);
		}
		i++;
	}
	return (0);
}

int	check_args_char(int argc, char **argv)
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
				return (error_exit(6, NULL), 1);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j
				- 1] != ' ' && j != 0)
				return (error_exit(6, NULL), 1);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (argv[i][j + 1] == '\0' || ft_isdigit(argv[i][j + 1]) == 0)
					return (error_exit(6, NULL), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (check_args_empty(argc, argv))
		return (1);
	if (check_args_char(argc, argv))
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int		j;

	j = 2;
	if (argc != 5 && argc != 6)
		return (error_exit(1, NULL), 1);
	if (check_args(argc, argv))
		return (1);
	if (ft_atol(argv[1]) < 1)
		return (1);
	while (j < argc)
	{
		if (ft_atol(argv[j]) == -1)
			return (1);
		j++;
	}
	return (0);
}
