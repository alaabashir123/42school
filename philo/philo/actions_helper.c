/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:41:15 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 16:55:00 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_odd(t_philo *philo)
{
	if (philo->id % 2 != 0 && philo->num_of_philos != 1)
	{
		printing(philo, "is thinking");
		ft_usleep(philo->time_to_eat, philo);
	}
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead != NULL && *(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	printing(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->write_lock);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->write_lock);
		return (1);
	}
	if (ft_strncmp(str, "is eating", 10) == 0)
	{
		printf("%lu %d %s\n", get_current_time() - philo->start_time, philo->id,
			"has taken a fork");
		printf("%lu %d %s\n", get_current_time() - philo->start_time, philo->id,
			str);
		pthread_mutex_unlock(philo->write_lock);
		return (0);
	}
	printf("%lu %d %s\n", get_current_time() - philo->start_time, philo->id,
		str);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

int	check_status(t_philo *philo)
{
	if (*(philo->right_status) != philo->id
		&& *(philo->left_status) != philo->id && *(philo->right_status) < 1000
		&& *(philo->left_status) < 1000)
	{
		*(philo->right_status) = philo->id;
		*(philo->left_status) = philo->id;
		return (0);
	}
	return (1);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	*(philo->right_status) -= 1000;
	*(philo->left_status) -= 1000;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
