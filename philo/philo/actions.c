/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:43:28 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 16:55:11 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	if (is_dead(philo))
		return (1);
	pthread_mutex_lock(&philo->general);
	philo->last_meal = get_current_time() - philo->start_time;
	philo->eating = 1;
	pthread_mutex_unlock(&philo->general);
	if (printing(philo, "is eating"))
		return (1);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(&philo->general);
	if (philo->num_times_to_eat != -1
		&& philo->meals_eaten < philo->num_times_to_eat)
		philo->meals_eaten++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->general);
	drop_forks(philo);
	return (0);
}

int	wait_fork_even(t_philo *philo)
{
	if (check_status(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		while (1)
		{
			if (is_dead(philo))
				return (1);
			usleep(5);
			pthread_mutex_lock(philo->r_fork);
			pthread_mutex_lock(philo->l_fork);
			if (check_status(philo) == 0)
				break ;
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
		}
	}
	return (0);
}

int	wait_fork_odd(t_philo *philo)
{
	if (check_status(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		while (1)
		{
			if (is_dead(philo))
				return (1);
			usleep(5);
			pthread_mutex_lock(philo->l_fork);
			pthread_mutex_lock(philo->r_fork);
			if (check_status(philo) == 0)
				break ;
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
		}
	}
	return (0);
}

int	takes_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		if (wait_fork_even(philo))
			return (1);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		if (wait_fork_odd(philo))
			return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	ft_odd(p);
	while (is_dead(p) == 0 && p->num_of_philos != 1)
	{
		if (takes_fork(p))
			return (NULL);
		if (*(p->right_status) == p->id && *(p->left_status) == p->id)
		{
			*(p->right_status) += 1000;
			*(p->left_status) += 1000;
			pthread_mutex_unlock(p->r_fork);
			pthread_mutex_unlock(p->l_fork);
			if (eating(p))
				return (NULL);
			if (printing(p, "is sleeping"))
				return (NULL);
			ft_usleep(p->time_to_sleep, p);
			if (printing(p, "is thinking"))
				return (NULL);
		}
	}
	return (NULL);
}
