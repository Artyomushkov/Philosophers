/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:14:57 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:17:54 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_param
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				times_must_eat;
	int				philosophers;
	int				dead;
	long long		start_time;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	*mutex_eating;
}				t_param;

typedef struct s_philo
{
	pthread_mutex_t	*mutex;
	int				num;
	t_param			*param;
	long long		last_time_eat;
	int				is_ate;
	pthread_mutex_t	is_eating;
	int				eating_now;
}				t_philo;

int			ft_atoi_changed(const char *str);
int			ft_param_init(int argc, char **argv, t_param *res);
long long	ft_get_time(long long last);
long long	ft_time(void);
t_philo		*ft_init_philosophers(t_param *param);
void		ft_print(int type, long long time, int num, t_philo philo);
void		ft_usleep(long long before, long long time);
void		*ft_philosopher(void *data);
void		*ft_monitor(void *data);

#endif
