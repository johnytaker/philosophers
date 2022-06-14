/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:42:14 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/14 18:12:17 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	set_one_philosopher_data(t_info *info, int thread_id)
{
	info->philosophers[thread_id].t_id = thread_id + 1;
	info->philosophers[thread_id].left_fork = \
		&info->forks[thread_id];
	info->philosophers[thread_id].right_fork = \
		&info->forks[thread_id + 1 % info->num_of_phil];
	info->philosophers[thread_id].meal_counter = 0;
	info->philosophers[thread_id].start_simulation = 0;
}

static void	set_all_philosophers_data(t_info *info)
{
	int	i;
	
	i = 0;
	while (i < info->num_of_phil)
		set_one_philosopher_data(info, i);
}

t_info	*parse_and_init(int argc, char **argv)
{
	t_info	*info;
	
	info = NULL;
	if (argc == 5 || argc == 6)
	{
		info = (t_info *)malloc(sizeof(t_info));
		if (!info)
			error("Allocate memory error\n");
		info->num_of_phil = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			info->number_of_time_to_meal = ft_atoi(argv[5]);
		info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			info->num_of_phil);
		if (!info->forks)
			error("Allocate memory error\n");
		info->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
			info->num_of_phil);
		if (!info->philosophers)
			error("Allocate memory error\n");
		set_all_philosophers_data(info);
	}
	else
		error("Wrong number of arguments\n");
	return (info);
}