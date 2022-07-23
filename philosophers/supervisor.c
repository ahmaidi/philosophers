/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:05:29 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 05:58:46 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock_it(pthread_mutex_t *a, pthread_mutex_t *b)
{
	pthread_mutex_lock(a);
	pthread_mutex_lock(b);
}

static void	unlock_it(pthread_mutex_t *a, pthread_mutex_t *b)
{
	pthread_mutex_unlock(a);
	pthread_mutex_unlock(b);
}

void	*supervisor(t_philo *philo, t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nbr_of_philo)
		{
			lock_it(&philo[i].data->check_eat, &philo[i].data->eat);
			if ((!philo[i].is_eating)
				&& (gettime_now() - philo[i].last_eat >= data->t_die))
			{
				pthread_mutex_lock(&philo[i].data->print);
				printf("%ld ms %d %s\n", gettime_now()
					- philo[i].data->t_start, philo[i].id,
					"\033[31m\033[1mis died 💀\033[0m");
				return (NULL);
			}
			unlock_it(&philo[i].data->check_eat, &philo[i].data->eat);
			i++;
		}
		pthread_mutex_lock(&philo->data->check_eat);
		if (finish_nbr_of_eat(philo, data))
			return (NULL);
		pthread_mutex_unlock(&philo->data->check_eat);
	}
}
