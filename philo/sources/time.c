/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:27:58 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 19:58:58 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	update_timestamp(t_info *info)
{
	info->timestamp = get_time() - \
		info->start_simulation;
}

void	update_last_meal(t_philosopher *philo)
{
	philo->last_meal = get_time() - \
		philo->info->start_simulation;
}

void	ft_time(int time)
{
	long long	pause;

	pause = get_time() + time;
	while (get_time() < pause)
		usleep(100);
}
