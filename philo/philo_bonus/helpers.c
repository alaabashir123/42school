/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:15:15 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 17:47:51 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

static void	init_sem(t_philo **philo)
{
	int	i;

	i = 0;
	sem_unlink("/block_write");
	sem_unlink("/block_forks");
	sem_unlink("/block_stop");
	sem_unlink("/block_meal");
	(*philo)->block_write = sem_open("/block_write", O_CREAT, 0644, 1);
	if ((*philo)->block_write == SEM_FAILED)
		error_exit(8, *philo);
	(*philo)->block_fork = sem_open("/block_forks", O_CREAT, 0644, 0);
	if ((*philo)->block_fork == SEM_FAILED)
		error_exit(8, *philo);
	while (i < (*philo)->num_philos)
	{
		sem_post((*philo)->block_fork);
		i++;
	}
	(*philo)->block_stop = sem_open("/block_stop", O_CREAT, 0644, 0);
	if ((*philo)->block_stop == SEM_FAILED)
		error_exit(8, *philo);
	(*philo)->block_meal = sem_open("/block_meal", O_CREAT, 0644, 1);
	if ((*philo)->block_meal == SEM_FAILED)
		error_exit(8, *philo);
}

t_philo	*init_philo(char **argv)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		error_exit(10, philo);
	philo->pid = ft_calloc(ft_atol(argv[1]), sizeof(int));
	if (!philo->pid)
		error_exit(10, philo);
	philo->num_philos = ft_atol(argv[1]);
	philo->t_die = ft_atol(argv[2]);
	philo->t_eat = ft_atol(argv[3]);
	philo->t_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->num_eat = ft_atol(argv[5]) + 1;
	else
		philo->num_eat = -1;
	philo->t_start = get_current_time();
	init_sem(&philo);
	return (philo);
}

void	create_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] < 0)
			error_exit(9, philo);
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			philo->t_meal = get_current_time();
			routine(philo);
		}
		i++;
	}
	sem_wait(philo->block_stop);
}
