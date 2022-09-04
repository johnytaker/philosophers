/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:42:14 by iugolin           #+#    #+#             */
/*   Updated: 2022/09/04 23:51:09 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_one_philosopher_data(t_info *info, int thread_id)
{
	if (pthread_mutex_init(&info->philosophers[thread_id].fork, NULL))
		return (RETURN_FAILURE);
	info->philosophers[thread_id].thread = NULL;
	info->philosophers[thread_id].t_id = thread_id + 1;
	info->philosophers[thread_id].death = 0;
	info->philosophers[thread_id].meal_counter = \
		info->number_of_time_to_meal;
	info->philosophers[thread_id].last_meal = 0;
	info->philosophers[thread_id].info = info;
	info->philosophers[thread_id].message = &info->print;
	info->philosophers[thread_id].left_fork = \
		&info->philosophers[thread_id].fork;
	info->philosophers[thread_id].right_fork = \
		&info->philosophers[(thread_id + 1) % info->num_of_phil].fork;
	return (RETURN_SUCCESS);
}

static int	set_all_philosophers_data(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_phil)
	{
		if (set_one_philosopher_data(info, i))
			return (RETURN_FAILURE);
		i++;
	}
	return (RETURN_SUCCESS);
}

static int	check_values(t_info *info)
{
	if (info->num_of_phil == -2 || \
		info->num_of_phil == 0)
		return (RETURN_FAILURE);
	if (info->time_to_die == -2 || \
		info->time_to_die == 0)
		return (RETURN_FAILURE);
	if (info->time_to_eat == -2 || \
		info->time_to_eat == 0)
		return (RETURN_FAILURE);
	if (info->time_to_sleep == -2 || \
		info->time_to_sleep == 0)
		return (RETURN_FAILURE);
	if (info->number_of_time_to_meal == -2 || \
		info->number_of_time_to_meal == 0)
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

static int	parser(t_info *info, char **argv)
{
	info->num_of_phil = ft_atoi_unsigned(argv[1]);
	info->time_to_die = ft_atoi_unsigned(argv[2]);
	info->time_to_eat = ft_atoi_unsigned(argv[3]);
	info->time_to_sleep = ft_atoi_unsigned(argv[4]);
	info->number_of_time_to_meal = -1;
	info->start_simulation = 0;
	if (argv[5])
		info->number_of_time_to_meal = ft_atoi_unsigned(argv[5]);
	return (check_values(info));
}

int	parse_and_init(t_info **info, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (print_usage());
	if (memory_allocation(info))
		return (print_error_and_free(*info, 2));
	if (parser(*info, argv))
		return (print_error_and_free(*info, 3));
	if (pthread_mutex_init(&(*info)->print, NULL))
		return (print_error_and_free(*info, 5));
	if (set_all_philosophers_data(*info))
		return (print_error_and_free(*info, 5));
	return (RETURN_SUCCESS);
}
