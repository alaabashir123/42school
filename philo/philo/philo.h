/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:07:29 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 16:55:37 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	int				*left_status;
	int				*right_status;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	general;
}					t_philo;

typedef struct s_program
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_philos;
	int				num_times_to_eat;
	int				dead_flag;
	int				*forks_status;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

int					check_input(int argc, char **argv);
int					ft_usleep(size_t milliseconds, t_philo *philo);
size_t				get_current_time(void);
void				init_connect(t_program *program);
t_program			*init_program(char **argv);
int					ft_isdigit(int c);
long long			ft_atol(const char *str);
void				error_exit(int error, t_program *program);
void				*monitor(void *p);
void				*routine(void *arg);
int					is_dead(t_philo *philo);
int					printing(t_philo *philo, char *str);
int					check_status(t_philo *philo);
void				drop_forks(t_philo *philo);
void				ft_odd(t_philo *philo);
void				free_program(t_program *program);
void				*ft_calloc(size_t count, size_t size);
void				init_connect(t_program *program);
int					run_threads(t_program *program);
void				end_program(t_program *program);
t_philo				*init_philos(t_program *program);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
