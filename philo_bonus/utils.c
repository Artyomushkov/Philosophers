/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:42:59 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 14:43:01 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(int type, long long time, t_param param)
{
	sem_wait(param.sems.print);
	if (type == 1)
		printf("%lld %d has taken a fork\n", time, param.num);
	if (type == 2)
		printf("%lld %d is eating\n", time, param.num);
	if (type == 3)
		printf("%lld %d is sleeping\n", time, param.num);
	if (type == 4)
		printf("%lld %d is thinking\n", time, param.num);
	sem_post(param.sems.print);
}

void	ft_usleep(long long before, long long time)
{
	while (ft_time() < (before + time))
		usleep(500);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size1;
	size_t	size2;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = malloc((size1 + size2) * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		result[i] = s2[i - size1];
		i++;
	}
	result[i] = '\0';
	return (result);
}
