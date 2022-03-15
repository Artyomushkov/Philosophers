/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changed_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:35:44 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:36:15 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static long long int	num_atoi(const char *str, int *err)
{
	int				i;
	long long int	buf;

	buf = 0;
	i = 0;
	if (str[i] == '-')
	{
		*err = 1;
		return (-1);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*err = 1;
			return (-1);
		}
		buf = 10 * buf + (str[i] - '0');
		i++;
	}
	return (buf);
}

int	ft_atoi_changed(const char *str)
{
	long long int	buf;
	int				result;
	int				err;

	err = 0;
	if (ft_strlen(str) > 18)
		return (-1);
	buf = num_atoi(str, &err);
	if (err == 1)
		return (-1);
	if (buf > 2147483647)
		return (-1);
	result = (int)(buf);
	return (result);
}
