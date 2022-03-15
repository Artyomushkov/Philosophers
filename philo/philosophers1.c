/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:22:34 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:23:51 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_choose_the_forks(int *first, int *second, t_philo *philo)
{
	if (philo->num == 1)
	{
		*first = philo->param->philosophers - 1;
		*second = philo->num - 1;
	}
	else
	{
		*first = philo->num - 2;
		*second = philo->num - 1;
	}
}

static void	ft_eating(t_philo *philo, int first_fork, int second_fork)
{
	pthread_mutex_lock(&(philo)->is_eating);
	philo->eating_now = 1;
	pthread_mutex_unlock(&(philo)->is_eating);
	ft_print(1, ft_get_time(philo->param->start_time), philo->num, *philo);
	ft_print(2, ft_get_time(philo->param->start_time), philo->num, *philo);
	philo->last_time_eat = ft_time();
	pthread_mutex_lock(&(philo)->is_eating);
	philo->eating_now = 0;
	pthread_mutex_unlock(&(philo)->is_eating);
	ft_usleep(philo->last_time_eat, philo->param->time_to_eat);
	pthread_mutex_unlock(&(philo->mutex[first_fork]));
	pthread_mutex_unlock(&(philo->mutex[second_fork]));
}

static void	ft_main_circle(t_philo *philo, int first_fork, int second_fork)
{
	int	k;

	k = 0;
	while (1)
	{
		if (philo->param->dead == 1)
			break ;
		pthread_mutex_lock(&(philo->mutex[first_fork]));
		ft_print(1, ft_get_time(philo->param->start_time), philo->num, *philo);
		if (second_fork == first_fork)
		{
			usleep(philo->param->time_to_die * 1000);
			return ;
		}
		pthread_mutex_lock(&(philo->mutex[second_fork]));
		ft_eating(philo, first_fork, second_fork);
		k++;
		if (k == philo->param->times_must_eat)
			philo->is_ate = 1;
		ft_print(3, ft_get_time(philo->param->start_time), philo->num, *philo);
		ft_usleep(philo->last_time_eat + philo->param->time_to_eat,
			philo->param->time_to_sleep);
		ft_print(4, ft_get_time(philo->param->start_time), philo->num, *philo);
	}
}

void	*ft_philosopher(void *data)
{
	t_philo			*philo;
	int				first_fork;
	int				second_fork;

	philo = (t_philo *)data;
	if (philo->param->times_must_eat == 0)
		return (0);
	ft_choose_the_forks(&first_fork, &second_fork, philo);
	if (philo->num % 2 != 0)
		usleep(philo->param->time_to_eat * 500);
	ft_main_circle(philo, first_fork, second_fork);
	return (0);
}
