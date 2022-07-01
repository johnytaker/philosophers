/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:38:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/30 22:42:02 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	free_all(t_info *info, t_philosopher *philosophers)
{
	if (philosophers)
		free(philosophers);
	if (info)
		free(info);
	return (RETURN_SUCCESS);
}

int	memory_allocation(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return (RETURN_FAILURE);
	(*info)->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
		(*info)->num_of_phil);
	if (!(*info)->philosophers)
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}
