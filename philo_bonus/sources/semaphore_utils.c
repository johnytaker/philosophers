/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:11:33 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/03 19:16:23 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	close_semaphores(t_info *info)
{
	if (sem_close(info->forks))
		return (RETURN_FAILURE);
	if (sem_close(info->print))
		return (RETURN_FAILURE);
	if (sem_close(info->data))
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

void	unlink_semaphores(void)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/data");
}

int	open_semaphores(t_info *info)
{
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->num_of_phil);
	if (info->forks == SEM_FAILED)
		return (RETURN_FAILURE);
	info->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (info->print == SEM_FAILED)
		return (RETURN_FAILURE);
	info->data = sem_open("/data", O_CREAT, S_IRWXU, 1);
	if (info->data == SEM_FAILED)
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}
