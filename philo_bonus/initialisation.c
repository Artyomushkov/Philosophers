/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:36:21 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:38:36 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sems_init(t_param *res)
{
	res->sems.print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	res->sems.dead = sem_open("dead", O_CREAT | O_EXCL, 0644, 0);
	res->sems.forks = sem_open("forks", O_CREAT | O_EXCL, 0644,
			res->philosophers);
	res->sems.eat = sem_open("eat", O_CREAT | O_EXCL, 0644, 1);
	if (res->sems.dead == SEM_FAILED || res->sems.print == SEM_FAILED
		|| res->sems.forks == SEM_FAILED || res->sems.eat == SEM_FAILED)
	{
		ft_clear_sem(res->sems);
		exit(3);
	}
}

int	ft_param_init(int argc, char **argv, t_param *res)
{
	res->philosophers = ft_atoi_changed(argv[1]);
	res->time_to_die = ft_atoi_changed(argv[2]);
	res->time_to_eat = ft_atoi_changed(argv[3]);
	res->time_to_sleep = ft_atoi_changed(argv[4]);
	res->start_time = ft_time();
	res->eating_now = 0;
	if (res->philosophers < 0 || res->time_to_die < 0 || res->time_to_eat < 0
		|| res->time_to_sleep < 0)
		return (-1);
	if (argc == 6)
	{
		res->times_must_eat = ft_atoi_changed(argv[5]);
		if (res->times_must_eat < 0)
			return (-1);
	}
	else
		res->times_must_eat = -1;
	return (0);
}
