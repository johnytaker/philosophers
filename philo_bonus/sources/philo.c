/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:17 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/01 01:58:33 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	kill_all(t_info *info)
// {
// 	int	counter;
// 	int	status;

// 	counter = -1;
// 	while (++counter < info->num_of_phil)
// 	{
// 		waitpid(-1, &status, 0);
// 		if (status)
// 		{
// 			counter = -1;
// 			while (++counter < info->num_of_phil)
// 				kill(info->philosophers[counter].pid, SIGKILL);
// 			break ;
// 		}
// 	}
// 	close_semaphores(info);
// 	unlink_semaphores();
// }

int	main(int argc, char **argv)
{
	t_info	*info;

	parse_and_init(&info, argc, argv);
	info->start_simulation = get_time();
	// printf("start %lld\n", info->start_simulation);
	create_all_processes(info);
	kill_all(info);
	free_all(info, info->philosophers);
	return (RETURN_SUCCESS);
}
