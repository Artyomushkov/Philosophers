/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:20:03 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:20:59 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_threads(pthread_t *thr, t_param param, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < param.philosophers)
	{
		if (pthread_create(&(thr[i]), NULL, &ft_philosopher, &(philo[i])) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&(thr[i]), NULL, &ft_monitor, philo) != 0)
		return (1);
	i = 0;
	while (i < param.philosophers)
	{
		pthread_join(thr[i], NULL);
		i++;
	}
	return (0);
}

static int	ft_init_args(int argc, char **argv, t_param *param)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (ft_param_init(argc, argv, param) == -1)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	return (0);
}

static void	ft_clearing(t_philo *philo, t_param param, pthread_t *thr)
{
	int	i;

	i = 0;
	while (i < param.philosophers)
	{
		pthread_mutex_destroy(&(philo[i].is_eating));
		pthread_mutex_destroy(&(philo[0].mutex[i]));
		i++;
	}
	free(thr);
	free(philo->mutex);
	pthread_mutex_destroy(&(param.is_dead));
	free(param.mutex_eating);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_param		param;
	pthread_t	*thr;

	if (ft_init_args(argc, argv, &param) == 1)
		return (1);
	if (param.philosophers == 0)
		return (0);
	thr = malloc(sizeof(pthread_t) * (param.philosophers + 1));
	if (thr == NULL)
		return (2);
	philo = ft_init_philosophers(&param);
	if (philo == NULL)
	{
		free(thr);
		return (2);
	}
	param.start_time = ft_time();
	if (ft_threads(thr, param, philo) == 1)
		return (3);
	ft_clearing(philo, param, thr);
	return (0);
}
