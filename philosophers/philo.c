/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:31:40 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 05:00:51 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo				*philo;
	t_data				*data;

	philo = NULL;
	data = NULL;
	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
		{
			data = int_data(argv);
			if (!init_forks(data))
				return (1);
			philo = init_philos(philo, data);
			if (!philo)
				return (3);
			create_threads(philo, data);
			supervisor(philo, data);
		}
		else
			ft_error("\033[91mOne of the arguments isn't a positive !!\n");
	}
	else
		ft_error("\033[91mless OR more arguments !!\n");
	return (0);
}
