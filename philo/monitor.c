/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:21:37 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:22:25 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_circle(t_philo *philo, int i, int *k)
{
	pthread_mutex_lock(&(philo->is_eating));
	pthread_mutex_unlock(&(philo->is_eating));
	if ((ft_time() - philo[i].last_time_eat)
		> philo[i].param->time_to_die && philo[i].eating_now == 0)
	{
		pthread_mutex_lock(&(philo[i].param->is_dead));
		philo->param->dead = 1;
		pthread_mutex_unlock(&(philo[i].param->is_dead));
		printf("%lld %d died\n", ft_get_time(philo[i].param->start_time),
			   philo[i].num);
		return (1);
	}
	if (philo[i].is_ate == 1)
		(*k)++;
	if (*k == philo[0].param->philosophers)
	{
		pthread_mutex_lock(&(philo[i].param->is_dead));
		philo->param->dead = 1;
		pthread_mutex_unlock(&(philo[i].param->is_dead));
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *data)
{
	int		i;
	int		k;
	t_philo	*philo;

	philo = (t_philo *)data;
	usleep(philo->param->time_to_die * 500);
	while (1)
	{
		i = 0;
		k = 0;
		while (i < philo[0].param->philosophers)
		{
			if (ft_philo_circle(philo, i, &k) == 1)
				return (0);
			i++;
		}
	}
}
