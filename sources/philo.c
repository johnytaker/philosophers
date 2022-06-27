/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:17 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/27 21:49:54 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
				// pthread_mutex_lock(&info->print);
				// printf("%lld %d died\n", info->timestamp, i + 1);

static int	death_case(t_info *info, int number)
{
	if (print_action(&info->philosophers[number], "died"))
		return (print_error_and_free(info, 6));
	if (destroy_mutexes(info))
		return (print_error_and_free(info, 8));
	return (RETURN_SUCCESS);
}

static int	death_check(t_info *info)
{
	int	i;
	int	j;

	while (1)
	{
		i = -1;
		j = 0;
		while (++i < info->num_of_phil)
		{
			update_timestamp(info);
			info->philosophers[i].death = \
				info->timestamp - info->philosophers[i].last_meal;
			if (info->philosophers[i].death > info->time_to_die)
			{
				if (death_case(info, i))
					return (RETURN_FAILURE);
				return (RETURN_SUCCESS);
			}
			if (info->philosophers[i].meal_counter == 0)
				j++;
		}
		if (j == info->num_of_phil)
			return (RETURN_SUCCESS);
	}
	return (RETURN_SUCCESS);
}

static int	dinner_party(t_info *info)
{
	info->start_simulation = get_time();
	if (create_threads(info))
		return (print_error_and_free(info, 4));
	if (detach_threads(info))
		return (print_error_and_free(info, 7));
	return (RETURN_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (parse_and_init(&info, argc, argv))
		return (RETURN_FAILURE);
	if (dinner_party(info))
		return (RETURN_FAILURE);
	if (death_check(info))
		return (RETURN_FAILURE);
	free_all(info, info->philosophers);
	return (EXIT_SUCCESS);
}
