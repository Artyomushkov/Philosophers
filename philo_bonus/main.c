/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:38:41 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:39:27 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_clear_sem(t_sems sems)
{
	sem_close(sems.eat);
	sem_close(sems.dead);
	sem_close(sems.print);
	sem_close(sems.forks);
	sem_unlink("dead");
	sem_unlink("eat");
	sem_unlink("print");
	sem_unlink("forks");
}

void	ft_forks(pid_t *proc, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philosophers)
	{
		proc[i] = fork();
		if (proc[i] < 0)
		{
			ft_clear_sem(param->sems);
			exit(4);
		}
		if (proc[i] == 0)
			ft_philosopher(i, param);
		i++;
	}
	i = 0;
	while (i < param->philosophers)
	{
		waitpid(proc[i], NULL, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_param		param;
	pid_t		*proc;

	ft_clear_sem(param.sems);
	if (ft_init_args(argc, argv, &param) == 1)
		exit (1);
	ft_sems_init(&param);
	proc = malloc(sizeof(pid_t) * param.philosophers);
	if (proc == NULL)
		exit (2);
	param.start_time = ft_time();
	param.last_time_eat = param.start_time;
	ft_forks(proc, &param);
	ft_clear_sem(param.sems);
	exit (0);
}
