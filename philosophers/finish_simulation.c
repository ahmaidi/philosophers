/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:07:48 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 06:01:10 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_nb_eat(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		if (philo[i].nb_of_eat < data->nb_of_eat)
			return (0);
		i++;
	}
	return (1);
}

int	finish_nbr_of_eat(t_philo *philo, t_data *data)
{
	if (data->nb_of_eat != -1)
	{
		if (check_nb_eat(philo, data))
		{
			pthread_mutex_lock(&philo->data->print);
			printf("\033[31m\033[1mFinish eating\n\033[0m");
			return (1);
		}
	}
	return (0);
}
