/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:12:26 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 15:57:50 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	program = NULL;
	if (check_input(argc, argv))
		return (1);
	program = init_program(argv);
	if (!program)
		return (1);
	program->philos = init_philos(program);
	if (!program->philos)
		return (1);
	init_connect(program);
	if (run_threads(program))
		return (1);
	end_program(program);
	return (0);
}
