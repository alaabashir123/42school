/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:11:36 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 15:59:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		if (*philo->dead == 1)
			return (1);
		usleep(500);
	}
	return (0);
}

int	run_threads(t_program *program)
{
	int			i;
	pthread_t	t_monitor;

	i = 0;
	if (pthread_create(&t_monitor, NULL, &monitor, program))
		return (error_exit(8, program), 1);
	while (i < program->n_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &routine, \
			&program->philos[i]))
			end_program(program);
		i++;
	}
	i = 0;
	while (i < program->n_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL))
			end_program(program);
		i++;
	}
	pthread_join(t_monitor, NULL);
	return (0);
}
