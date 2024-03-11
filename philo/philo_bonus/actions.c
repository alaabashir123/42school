/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:47:20 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 18:04:27 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	handle_forks(t_philo *philo, int flag)
{
	if (flag == 0)
	{
		sem_wait(philo->block_fork);
		sem_wait(philo->block_fork);
	}
	else
	{
		sem_post(philo->block_fork);
		sem_post(philo->block_fork);
	}
}

int	printing(t_philo *philo, char *str, int flag)
{
	sem_wait(philo->block_write);
	if (ft_strncmp(str, "is eating", 10) == 0)
	{
		printf("%lu %d %s\n", get_current_time() - philo->t_start, philo->index,
			"has taken a fork");
		printf("%lu %d %s\n", get_current_time() - philo->t_start, philo->index,
			str);
		sem_post(philo->block_write);
		return (0);
	}
	printf("%lu %d %s\n", get_current_time() - philo->t_start, philo->index,
		str);
	if (flag == 0)
		sem_post(philo->block_write);
	return (0);
}

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		usleep(500);
		sem_wait(philo->block_meal);
		if ((get_current_time() - philo->t_meal > philo->t_die)
			&& philo->eating == 0)
		{
			sem_post(philo->block_meal);
			printing(philo, "died", 1);
			sem_post(philo->block_stop);
			break ;
		}
		if (philo->num_eat != -1 && philo->num_eat_count >= philo->num_eat)
		{
			sem_post(philo->block_meal);
			sem_post(philo->block_stop);
			break ;
		}
		sem_post(philo->block_meal);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	printing(philo, "is eating", 0);
	sem_wait(philo->block_meal);
	philo->t_meal = get_current_time();
	philo->eating = 1;
	sem_post(philo->block_meal);
	ft_usleep(philo->t_eat);
	sem_wait(philo->block_meal);
	philo->eating = 0;
	philo->num_eat_count++;
	sem_post(philo->block_meal);
}

void	routine(t_philo *philo)
{
	pthread_create(&philo->check_monitor, NULL, &monitor, philo);
	pthread_detach(philo->check_monitor);
	if (philo->index % 2 == 0)
	{
		printing(philo, "is thinking", 0);
		ft_usleep(philo->t_eat);
	}
	while (1)
	{
		handle_forks(philo, 0);
		eating(philo);
		handle_forks(philo, 1);
		printing(philo, "is sleeping", 0);
		ft_usleep(philo->t_sleep);
		printing(philo, "is thinking", 0);
	}
}
