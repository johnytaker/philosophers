/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:17 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/04 11:32:55 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_and_kill(t_info *info)
{
	int	pid;
	int	status;
	int	i;

	pid = waitpid(-1, &status, 0);
	if (pid == -1)
		print_error_and_exit(10);
	else if (WIFEXITED(status))
	{
		i = -1;
		while (++i < info->num_of_phil)
			kill(info->philosophers[i].pid, SIGKILL);
	}
	close_semaphores(info);
	unlink_semaphores();
}

int	main(int argc, char **argv)
{
	t_info	*info;

	parse_and_init(&info, argc, argv);
	create_all_processes(info);
	wait_and_kill(info);
	free_all(info, info->philosophers);
	return (RETURN_SUCCESS);
}
