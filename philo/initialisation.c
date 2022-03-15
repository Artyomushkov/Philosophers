/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:13:53 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:19:35 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_struct_get_ready(pthread_mutex_t	*mutex, t_philo	**res,
								pthread_mutex_t *buf, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philosophers)
	{
		pthread_mutex_init(&buf[i], NULL);
		(*res)[i].is_eating = buf[i];
		(*res)[i].eating_now = 0;
		(*res)[i].mutex = mutex;
		(*res)[i].is_ate = 0;
		(*res)[i].last_time_eat = param->start_time;
		(*res)[i].num = i + 1;
		(*res)[i].param = param;
		i++;
	}
}

t_philo	*ft_init_philosophers(t_param *param)
{
	int				i;
	pthread_mutex_t	*mutex;
	t_philo			*res;
	pthread_mutex_t	*buf;

	mutex = malloc(sizeof(pthread_mutex_t) * (param->philosophers));
	buf = malloc(sizeof(pthread_mutex_t) * (param->philosophers));
	param->mutex_eating = buf;
	if (mutex == NULL)
		return (NULL);
	i = 0;
	while (i != param->philosophers)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	res = malloc(sizeof(t_philo) * (param->philosophers));
	if (res == NULL)
	{
		free(mutex);
		return (NULL);
	}
	ft_struct_get_ready(mutex, &res, buf, param);
	return (res);
}

int	ft_param_init(int argc, char **argv, t_param *res)
{
	res->philosophers = ft_atoi_changed(argv[1]);
	res->time_to_die = ft_atoi_changed(argv[2]);
	res->time_to_eat = ft_atoi_changed(argv[3]);
	res->time_to_sleep = ft_atoi_changed(argv[4]);
	res->start_time = ft_time();
	res->dead = 0;
	pthread_mutex_init(&(res->is_dead), NULL);
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
