/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:23:03 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/21 16:54:14 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philos(t_philo *philo, t_data *data)
{
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].nb_of_eat = 0;
		philo[i].left = &data->forks[i];
		philo[i].right = &data->forks[(i + 1) % data->nbr_of_philo];
		pthread_mutex_init(&philo[i].data->check_eat, NULL);
		pthread_mutex_init(&philo[i].data->eat, NULL);
		i++;
	}
	return (philo);
}
