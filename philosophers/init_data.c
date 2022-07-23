/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:07 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/19 16:04:32 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*int_data(char **argv)
{
	t_data	*data;

	if (ft_atoi(argv[1]))
	{
		data = malloc(sizeof(t_data));
		data->nbr_of_philo = ft_atoi(argv[1]);
		data->t_die = ft_atoi(argv[2]);
		data->t_eat = ft_atoi(argv[3]);
		data->t_sleep = ft_atoi(argv[4]);
		data->nb_of_eat = -1;
		if (argv[5] != NULL)
			data->nb_of_eat = ft_atoi(argv[5]);
	}
	else
		return (NULL);
	return (data);
}
