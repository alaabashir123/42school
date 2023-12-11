/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:46:03 by abashir           #+#    #+#             */
/*   Updated: 2023/09/20 11:02:21 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		error_exit(0, 0, 0);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			error_exit(1, 0, 0);
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				error_exit(1, 0, 0);
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
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-' \
			&& argv[i][j] != '+' && argv[i][j] != ' ')
				error_exit(1, 0, 0);
			if ((argv[i][j] == '-' || argv[i][j] == '+') \
			&& argv[i][j - 1] != ' ' && j != 0)
				error_exit(1, 0, 0);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (argv[i][j + 1] == '\0' || ft_isdigit(argv[i][j + 1]) == 0)
					error_exit(1, 0, 0);
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
