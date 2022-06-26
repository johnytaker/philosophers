/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:38:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 20:40:23 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_info *info, pthread_mutex_t *forks, \
	t_philosopher *philosophers)
{
	if (forks)
		free(forks);
	if (philosophers)
		free(philosophers);
	if (info)
		free(info);
	return (EXIT_FAILURE);
}

int	memory_allocation(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return (1);
	(*info)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
		(*info)->num_of_phil);
	if (!(*info)->forks)
		return (free_all(*info, 0, 0));
	(*info)->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
		(*info)->num_of_phil);
	if (!(*info)->philosophers)
		return (free_all(*info, (*info)->forks, 0));
	return (0);
}
