/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:25:39 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:26:09 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(int type, long long time, int num, t_philo philo)
{
	pthread_mutex_lock(&(philo.param->is_dead));
	if (philo.param->dead == 1)
	{
		pthread_mutex_unlock(&(philo.param->is_dead));
		return ;
	}
	pthread_mutex_unlock(&(philo.param->is_dead));
	if (type == 1)
		printf("%lld %d has taken a fork\n", time, num);
	if (type == 2)
		printf("%lld %d is eating\n", time, num);
	if (type == 3)
		printf("%lld %d is sleeping\n", time, num);
	if (type == 4)
		printf("%lld %d is thinking\n", time, num);
}

void	ft_usleep(long long before, long long time)
{
	while (ft_time() < (before + time))
		usleep(500);
}
