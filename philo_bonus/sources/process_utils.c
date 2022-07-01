/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/01 09:41:19 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_info *info)
{
	int		counter;
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, 0);
	if (pid == -1)
		print_error_and_exit(11);
	else
	{
		if (WIFEXITED(status))
		{
			counter = -1;
			while (++counter < info->num_of_phil)
				kill(info->philosophers[counter].pid, SIGTERM);
		}
	}
	close_semaphores(info);
	unlink_semaphores();
	// exit(EXIT_SUCCESS);
}

static void	create_one_process(t_philosopher *philo)
{
	philo->pid = fork();
	if (philo->pid == 0)
		execution(philo);
	else if (philo->pid == -1)
		print_error_and_exit(4);
}

void	create_all_processes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_phil)
	{
		create_one_process(&info->philosophers[i]);
		usleep(1000);
	}
}
