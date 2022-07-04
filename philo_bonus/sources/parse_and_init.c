/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:42:14 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/04 11:16:17 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	set_one_philosopher_data(t_info *info, int thread_id)
{
	info->philosophers[thread_id].philo_id = thread_id + 1;
	info->philosophers[thread_id].death_counter = 0;
	info->philosophers[thread_id].meal_counter = \
		info->number_of_time_to_meal;
	info->philosophers[thread_id].last_meal = 0;
	info->philosophers[thread_id].timestamp = 0;
	info->philosophers[thread_id].start_time = get_time();
	info->philosophers[thread_id].info = info;
}

static void	set_all_philosophers_data(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_phil)
		set_one_philosopher_data(info, i);
}

static int	check_values(t_info *info)
{
	if (info->num_of_phil == -2 || \
		info->num_of_phil == 0)
		return (RETURN_FAILURE);
	if (info->time_to_die == -2 || \
		info->time_to_die < 60)
		return (RETURN_FAILURE);
	if (info->time_to_eat == -2 || \
		info->time_to_eat < 60)
		return (RETURN_FAILURE);
	if (info->time_to_sleep == -2 || \
		info->time_to_sleep < 60)
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
	if (argv[5])
		info->number_of_time_to_meal = ft_atoi_unsigned(argv[5]);
	return (check_values(info));
}

void	parse_and_init(t_info **info, int argc, char **argv)
{
	if (memory_allocation(info))
		print_error_and_exit(2);
	if (argc != 5 && argc != 6)
		print_error_and_exit(1);
	if (parser(*info, argv))
		print_error_and_exit(3);
	unlink_semaphores();
	open_semaphores(*info);
	set_all_philosophers_data(*info);
}
