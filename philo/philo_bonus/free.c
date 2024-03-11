/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:08:38 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 15:02:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_philo(t_philo *philo)
{
	if (philo)
	{
		if (philo->pid)
			free(philo->pid);
		if (philo->block_write)
			sem_close(philo->block_write);
		if (philo->block_fork)
			sem_close(philo->block_fork);
		if (philo->block_stop)
			sem_close(philo->block_stop);
		if (philo->block_meal)
			sem_close(philo->block_meal);
		free(philo);
	}
}

void	error_exit(int error, t_philo *philo)
{
	if (error == 1)
		printf("Usage: no_philos time_die time_eat time_sleep \
		[no_of_times_eat]\n");
	if (error == 2)
		printf("Error: Invalid number of philos.\n");
	if (error == 3)
		printf("Error: Time must be positive and within int max.\n");
	if (error == 4)
		printf("Error: Times to eat must be positive and within int max.\n");
	if (error == 5)
		printf("Error: Empty argument.\n");
	if (error == 6)
		printf("Error: Invalid input.\n");
	if (error == 7)
		printf("Error: Thread creation failed.\n");
	if (error == 8)
		printf("Error: Semaphore creation failed.\n");
	if (error == 9)
		printf("Error: Process creation failed.\n");
	if (error == 10)
		printf("Error: Mallock failed.\n");
	free_philo(philo);
	exit(1);
}

void	end_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
		kill(philo->pid[i++], SIGKILL);
	sem_close(philo->block_write);
	sem_close(philo->block_fork);
	sem_close(philo->block_stop);
	sem_close(philo->block_meal);
	sem_unlink("/block_write");
	sem_unlink("/block_forks");
	sem_unlink("/block_stop");
	sem_unlink("/block_meal");
	free(philo->pid);
	free(philo);
}
