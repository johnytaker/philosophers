/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 20:54:56 by iugolin          ###   ########.fr       */
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
			return (EXIT_FAILURE);
		i += 2;
		usleep(1000);
	}
	usleep(300);
	i = 1;
	while (i < info->num_of_phil)
	{
		if (pthread_create(&info->philosophers[i].thread, NULL, \
				execution, &info->philosophers[i]))
			return (EXIT_FAILURE);
		i += 2;
		usleep(1000);
	}
	return (EXIT_SUCCESS);
}

int	create_mutexes(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->print, NULL))
		return (EXIT_FAILURE);
	while (i < info->num_of_phil)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

// int	join_threads(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (i < info->num_of_phil)
// 	{
// 		if (pthread_join(info->philosophers[i++].thread, NULL))
// 			return (1);
// 	}
// 	return (0);
// }

int	detach_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_phil)
	{
		if (pthread_detach(info->philosophers[i].thread))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutexes(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&info->print))
		return (EXIT_FAILURE);
	while (i < info->num_of_phil)
	{
		if (pthread_mutex_destroy(&info->forks[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
