/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:45:39 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 15:41:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_program(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_philos)
	{
		pthread_mutex_destroy(&program->philos[i].general);
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	free_program(program);
}

void	free_program(t_program *program)
{
	if (program)
	{
		if (program->forks)
			free(program->forks);
		if (program->forks_status)
			free(program->forks_status);
		if (program->philos)
			free(program->philos);
		free(program);
		program = NULL;
	}
}

void	error_exit(int error, t_program *program)
{
	if (error == 1)
		printf("Usage: no_philos time_die time_eat time_sleep \
		[no_of_times_eat]\n");
	if (error == 2)
		printf("Error: Inalid number of philos.\n");
	if (error == 3)
		printf("Error: Time must be positive and within int max.\n");
	if (error == 4)
		printf("Error: Times to eat must be positive and within int max.\n");
	if (error == 5)
		printf("Error: Empty argument.\n");
	if (error == 6)
		printf("Error: Invalid input.\n");
	if (error == 7)
		printf("Error: Mutex init failed.\n");
	if (error == 8)
		printf("Error: Thread creation failed.\n");
	if (error == 9)
		printf("Error: Mallloc failed.\n");
	free_program(program);
}
