/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:07:29 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 17:20:08 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	int			num_philos;
	size_t		t_die;
	size_t		t_eat;
	size_t		t_sleep;
	int			num_eat;
	int			num_eat_count;
	int			eating;
	int			*pid;
	int			index;
	sem_t		*block_write;
	sem_t		*block_fork;
	sem_t		*block_stop;
	sem_t		*block_meal;
	size_t		t_start;
	size_t		t_meal;
	pthread_t	check_monitor;
}				t_philo;

typedef struct s_args
{
	t_philo		*philo;
	sem_t		*block;
}				t_args;

int				check_input(int argc, char **argv);
int				ft_isdigit(int c);
void			error_exit(int error, t_philo *philo);
long long		ft_atol(const char *str);
int				ft_usleep(size_t milliseconds);
size_t			get_current_time(void);
t_philo			*init_philo(char **argv);
void			routine(t_philo *philo);
void			create_process(t_philo *philo);
void			end_process(t_philo *philo);
void			*ft_calloc(size_t count, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
