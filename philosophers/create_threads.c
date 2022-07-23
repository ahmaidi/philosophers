/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:54:51 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 03:57:26 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		printf_msg(philo, "\033[90m\033[1mis thinkig\033[0m");
		pthread_mutex_lock(&philo->data->eat);
		philo->is_eating = 0;
		pthread_mutex_unlock(&philo->data->eat);
	}
	return (NULL);
}

int	create_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data->t_start = gettime_now();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->finish, NULL);
	while (i < data->nbr_of_philo)
	{
		philo[i].last_eat = gettime_now();
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (3);
		usleep(100);
		i++;
	}
	return (0);
}
