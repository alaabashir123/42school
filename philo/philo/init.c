/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:54:21 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/31 15:59:36 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*init_program(char **argv)
{
	t_program	*program;

	program = ft_calloc(sizeof(t_program), 1);
	if (!program)
		return (error_exit(9, program), NULL);
	program->forks = ft_calloc(sizeof(pthread_mutex_t), ft_atol(argv[1]));
	if (!program->forks)
		return (error_exit(9, program), NULL);
	program->forks_status = ft_calloc(sizeof(int), ft_atol(argv[1]));
	if (!program->forks_status)
		return (error_exit(9, program), NULL);
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	program->n_philos = ft_atol(argv[1]);
	if (argv[5])
		program->num_times_to_eat = ft_atol(argv[5]);
	else
		program->num_times_to_eat = -1;
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		return (error_exit(7, program), NULL);
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		return (error_exit(7, program), NULL);
	return (program);
}

int	init_each_philo(t_philo **philo, t_program *p, int i)
{
	t_philo	*philos;

	philos = *philo;
	if (pthread_mutex_init(&p->forks[i], NULL) != 0)
		return (error_exit(7, p), 1);
	philos[i].right_status = &p->forks_status[(i + 1) % p->n_philos];
	philos[i].left_status = &p->forks_status[i];
	philos[i].r_fork = &p->forks[i];
	philos[i].l_fork = &p->forks[(i + 1) % p->n_philos];
	philos[i].id = i + 1;
	philos[i].num_of_philos = p->n_philos;
	philos[i].time_to_die = p->time_to_die;
	philos[i].time_to_eat = p->time_to_eat;
	philos[i].time_to_sleep = p->time_to_sleep;
	philos[i].start_time = get_current_time();
	philos[i].num_times_to_eat = p->num_times_to_eat;
	if (pthread_mutex_init(&philos[i].general, NULL) != 0)
		return (error_exit(7, p), 1);
	return (0);
}

t_philo	*init_philos(t_program *p)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = ft_calloc(sizeof(t_philo), p->n_philos);
	if (!philos)
		return (error_exit(9, p), NULL);
	while (i < p->n_philos)
	{
		if (init_each_philo(&philos, p, i))
			return (NULL);
		i++;
	}
	return (philos);
}

void	init_connect(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_philos)
	{
		program->philos[i].write_lock = &(program->write_lock);
		program->philos[i].dead_lock = &(program->dead_lock);
		program->philos[i].dead = &(program->dead_flag);
		i++;
	}
}
