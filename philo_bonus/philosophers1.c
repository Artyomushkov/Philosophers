/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:40:58 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:41:41 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitor_here(void *data)
{
	t_param	*param;

	param = (t_param *)data;
	usleep(param->time_to_die * 500);
	while (1)
	{
		sem_wait(param->sems.eat);
		sem_post(param->sems.eat);
		if ((ft_time() - param->last_time_eat) > param->time_to_die
			&& param->eating_now == 0)
		{
			sem_wait(param->sems.print);
			printf("%lld %d died\n", ft_get_time(param->start_time), param->num);
			sem_post(param->sems.dead);
			return (0);
		}
	}
}

void	*ft_monitor_any(void *data)
{
	t_param	*param;

	param = (t_param *)data;
	sem_wait(param->sems.dead);
	sem_post(param->sems.dead);
	exit (0);
}

static void	ft_main_circle(t_param *param)
{
	int	k;

	k = 0;
	while (k != param->times_must_eat)
	{
		sem_wait(param->sems.forks);
		ft_print(1, ft_get_time(param->start_time), *param);
		sem_wait(param->sems.forks);
		sem_wait(param->sems.eat);
		param->eating_now = 1;
		param->last_time_eat = ft_time();
		sem_post(param->sems.eat);
		ft_print(1, ft_get_time(param->start_time), *param);
		ft_print(2, ft_get_time(param->start_time), *param);
		ft_usleep(param->last_time_eat, param->time_to_eat);
		sem_post(param->sems.forks);
		sem_post(param->sems.forks);
		param->eating_now = 0;
		k++;
		ft_print(3, ft_get_time(param->start_time), *param);
		ft_usleep(param->last_time_eat + param->time_to_eat,
			param->time_to_sleep);
		ft_print(4, ft_get_time(param->start_time), *param);
		usleep(500);
	}
}

void	ft_philosopher(int num, t_param *param)
{
	pthread_t	monitor_death_here;
	pthread_t	monitor_death_anywhere;

	param->num = num + 1;
	pthread_create(&monitor_death_here, NULL, &ft_monitor_here, param);
	pthread_detach(monitor_death_here);
	pthread_create(&monitor_death_anywhere, NULL, &ft_monitor_any, param);
	pthread_detach(monitor_death_anywhere);
	if (param->num % 2 != 0)
		usleep(param->time_to_eat * 300);
	if (param->num == param->philosophers && param->num % 2 != 0)
		usleep(param->time_to_eat * 600);
	ft_main_circle(param);
	exit(0);
}
