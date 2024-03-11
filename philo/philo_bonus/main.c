/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:12:26 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 13:50:25 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	check_input(argc, argv);
	philo = init_philo(argv);
	create_process(philo);
	end_process(philo);
	return (0);
}
