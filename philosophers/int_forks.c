/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:18:17 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/19 16:04:35 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_forks(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return (NULL);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nbr_of_philo);
	if (!data->forks)
		return (NULL);
	while (i < data->nbr_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (NULL);
		i++;
	}
	return (data);
}
