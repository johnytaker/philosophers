/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/27 22:28:19 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_phil)
	{
		if (pthread_create(&info->philosophers[i].thread, NULL, \
				execution, &info->philosophers[i]))
			return (RETURN_FAILURE);
		i += 2;
	}
	usleep(300);
	i = 1;
	while (i < info->num_of_phil)
	{
		if (pthread_create(&info->philosophers[i].thread, NULL, \
				execution, &info->philosophers[i]))
			return (RETURN_FAILURE);
		i += 2;
	}
	return (RETURN_SUCCESS);
}

int	detach_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_phil)
	{
		if (pthread_detach(info->philosophers[i].thread))
			return (RETURN_FAILURE);
		i++;
	}
	return (RETURN_SUCCESS);
}

int	destroy_mutexes(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&info->print))
	{
		pthread_mutex_unlock(&info->print);
		if (pthread_mutex_destroy(&info->print))
			return (RETURN_FAILURE);
	}
	while (i < info->num_of_phil)
	{
		if (pthread_mutex_destroy(&info->philosophers[i].fork))
		{
			pthread_mutex_unlock(&info->philosophers[i].fork);
			if (pthread_mutex_destroy(&info->philosophers[i].fork))
				return (RETURN_FAILURE);
		}
		i++;
	}
	return (RETURN_SUCCESS);
}
