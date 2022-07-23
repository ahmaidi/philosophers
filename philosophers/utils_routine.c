/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:35:29 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 05:11:08 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_msg(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms %d %s\n", gettime_now() - philo->data->t_start, philo->id, s);
	pthread_mutex_unlock(&philo->data->print);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	printf_msg(philo, "\033[94m\033[1mhas taken a fork 🍴🤚\033[0m");
	pthread_mutex_lock(philo->right);
	printf_msg(philo, "\033[94m\033[1mhas taken a fork ✋🍴\033[0m");
}

void	puts_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->check_eat);
	philo->is_eating = 1;
	philo->last_eat = gettime_now();
	printf_msg(philo, "\033[32m\033[1mis eating 🍽️\033[0m");
	philo->nb_of_eat++;
	pthread_mutex_unlock(&philo->data->check_eat);
	ft_usleep(philo->data->t_eat * 1000);
	puts_forks(philo);
}

void	sleeping(t_philo *philo)
{
	printf_msg(philo, "\033[33m\033[1mis sleeping 😴\033[0m");
	ft_usleep(philo->data->t_sleep * 1000);
}
