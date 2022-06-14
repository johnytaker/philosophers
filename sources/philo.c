/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:17 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/14 18:11:05 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	info = parse_and_init(argc, argv);
	printf("number of philosophers - %d\n", info->num_of_phil);
	printf("time to die - %d\n", info->time_to_die);
	printf("time to eat - %d\n", info->time_to_eat);
	printf("time to sleep - %d\n", info->time_to_sleep);
	if (argc == 6)
		printf("number of_time_to meal - %d \n", info->number_of_time_to_meal);
	// i = 0;
	// while (i < info->num_of_phil)
	// 	printf("fork #%d pointer - %p\n", i + 1, (void *)info->forks[i]);
	i = 0;
	while (i < info->num_of_phil)
	{
		printf("t_id - %d\n", info->philosophers[i].t_id);
		printf("meal_counter - %d\n", info->philosophers[i].meal_counter);
		printf("start simulation - %lld\n", info->philosophers[i].start_simulation);
		printf("left fork pointer - %p\n", info->philosophers[i].left_fork);
		printf("right fork pointer - %p\n", info->philosophers[i].right_fork);
		i++;
	}
	return (0);
}