/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:11:33 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/04 11:15:01 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_semaphores(t_info *info)
{
	if (sem_close(info->forks))
		print_error_and_exit(11);
	if (sem_close(info->print))
		print_error_and_exit(11);
	if (sem_close(info->data))
		print_error_and_exit(11);
}

void	unlink_semaphores(void)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/data");
}

void	open_semaphores(t_info *info)
{
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->num_of_phil);
	if (info->forks == SEM_FAILED)
		print_error_and_exit(5);
	info->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (info->print == SEM_FAILED)
		print_error_and_exit(5);
	info->data = sem_open("/data", O_CREAT, S_IRWXU, 1);
	if (info->data == SEM_FAILED)
		print_error_and_exit(5);
}
