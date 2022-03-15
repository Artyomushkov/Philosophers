/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:33:21 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:35:26 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct s_sems
{
	sem_t	*dead;
	sem_t	*print;
	sem_t	*forks;
	sem_t	*eat;
}				t_sems;

typedef struct s_param
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				times_must_eat;
	int				philosophers;
	long long		start_time;
	long long		last_time_eat;
	int				num;
	int				eating_now;
	t_sems			sems;
}				t_param;

int			ft_atoi_changed(const char *str);
int			ft_param_init(int argc, char **argv, t_param *res);
long long	ft_get_time(long long last);
long long	ft_time(void);
void		ft_print(int type, long long time, t_param param);
void		ft_usleep(long long before, long long time);
void		ft_philosopher(int num, t_param *param);
void		*ft_monitor(void *data);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_clear_sem(t_sems sems);
size_t		ft_strlen(const char *s);
void		ft_sems_init(t_param *res);

#endif
