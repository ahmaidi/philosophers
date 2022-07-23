/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:31:36 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 04:59:55 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nbr_of_philo;
	pthread_mutex_t	*forks;
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				nb_of_eat;
	long			t_start;
	pthread_mutex_t	print;
	pthread_mutex_t	finish;
	pthread_mutex_t	check_eat;
	pthread_mutex_t	eat;
}t_data;

typedef struct s_philo
{
	int				id;
	int				nb_of_eat;
	int				is_eating;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	long			last_eat;
}t_philo;

int		is_number(char *str);
int		check_args(int ac, char **ar);
int		ft_atoi(const char *str);
t_data	*int_data(char **argv);
long	gettime_now(void);
t_data	*init_forks(t_data *data);
t_philo	*init_philos(t_philo *philo, t_data *data);
int		create_threads(t_philo *philo, t_data *data);
void	printf_msg(t_philo *philo, char *s);
void	take_forks(t_philo *philo);
void	puts_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	ft_usleep(useconds_t time);
void	ft_error(char *s);
size_t	ft_strlen(const char *s);
void	*supervisor(t_philo *philo, t_data *data);
int		finish_nbr_of_eat(t_philo *philo, t_data *data);
#endif