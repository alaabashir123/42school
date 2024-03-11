/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:11:17 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 16:47:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end(t_program *program, char *msg, int i)
{
	pthread_mutex_lock(&program->dead_lock);
	program->dead_flag = 1;
	pthread_mutex_unlock(&program->dead_lock);
	pthread_mutex_lock(&program->write_lock);
	if (i != -1)
	{
		printf("%lu %d %s\n", get_current_time()
			- program->philos[i].start_time, program->philos[i].id, msg);
	}
	pthread_mutex_unlock(&program->write_lock);
}

int	check_time(t_program *program, int i)
{
	if (((get_current_time() - program->philos[i].start_time
				- program->philos[i].last_meal) > program->philos[i].time_to_die
			+ 2 && program->philos[i].eating == 0))
	{
		set_end(program, "died", i);
		return (1);
	}
	return (0);
}

int	check_meals(t_program *p, int i)
{
	int	j;

	if (p->philos[i].num_times_to_eat != -1
		&& p->philos[i].meals_eaten == p->philos[i].num_times_to_eat)
	{
		pthread_mutex_unlock(&p->philos[i].general);
		j = 0;
		while (j < p->n_philos)
		{
			pthread_mutex_lock(&p->philos[j].general);
			if (p->philos[j].meals_eaten != p->philos[j].num_times_to_eat)
			{
				pthread_mutex_unlock(&p->philos[j].general);
				break ;
			}
			pthread_mutex_unlock(&p->philos[j].general);
			j++;
		}
		if (j == p->n_philos)
		{
			set_end(p, "", -1);
			return (1);
		}
	}
	return (0);
}

void	*monitor(void *input)
{
	int			i;
	t_program	*program;

	program = (t_program *)input;
	while (1)
	{
		i = 0;
		while (i < program->n_philos)
		{
			pthread_mutex_lock(&program->philos[i].general);
			if (check_time(program, i))
				return (pthread_mutex_unlock(&program->philos[i].general),
					NULL);
			pthread_mutex_unlock(&program->philos[i].general);
			pthread_mutex_lock(&program->philos[i].general);
			if (check_meals(program, i))
				return (pthread_mutex_unlock(&program->philos[i].general),
					NULL);
			pthread_mutex_unlock(&program->philos[i].general);
			i++;
		}
	}
}
