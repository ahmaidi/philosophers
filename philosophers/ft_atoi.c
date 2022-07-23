/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:47:07 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/06/23 04:49:11 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static const char	*ft_del_fespace(const char *str)
{
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\f' || *str == '\v' || *str == '\r'))
	{
		str++;
	}
	return (str);
}

static int	convert_to_number(const char *str, int sign)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	while (*(str + i) && ft_isdigit(*(str + i)))
	{
		if (res >= 214748364)
		{
			if ((res > 214748364 || *(str + i) - '0' > 7) && sign > 0)
				return (0);
			if ((res > 214748364 || *(str + i) - '0' > 8) && sign < 0)
				return (0);
		}
		res = res * 10 + (*(str + i) - '0');
		i++;
	}
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (res);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	str = ft_del_fespace(str);
	if (str[0] == '-' || str[0] == '0')
		return (0);
	else if (str[0] == '+')
		str++;
	res = convert_to_number(str, sign);
	return (res * sign);
}
