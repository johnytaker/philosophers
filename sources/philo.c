/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:17 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 20:54:31 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	death_case(t_philosopher *philosopher)
// {
// 	pthread_mutex_lock(&philosopher->info->print);
// 	philosopher->info->timestamp = get_time() - \
// 		philosopher->info->start_simulation;
// 	printf("%lld %d died\n", \
// 		philosopher->info->timestamp, philosopher->t_id);
// 	pthread_mutex_unlock(&philosopher->info->print);
// 	if (detach_threads(philosopher->info))
// 		return (print_error_and_free(philosopher->info, 8));
// 	if (destroy_mutexes(philosopher->info))
// 		return (print_error_and_free(philosopher->info, 9));
// 	return (EXIT_SUCCESS);
// }

// static int	main_loop(t_info *info)
// {
// 	int	i;

// 	while (1)
// 	{
// 		i = 0;
// 		while (!info->philosophers[i].death)
// 		{
// 			// printf("CHECK\n");
// 			i++;
// 		}
// 		if (info->philosophers[i].death)
// 		{
// 			if (death_case(&info->philosophers[i]))
// 				return (EXIT_FAILURE);
// 			break ;
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }

static int	death_check(t_info *info)
{
	int	i;
	int	j;

	if (info->num_of_phil == 1)
		return (one_philosopher_case(info->philosophers));
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
				pthread_mutex_lock(&info->print);
				printf("%lld %d died\n", info->timestamp, i + 1);
				pthread_mutex_unlock(&info->print);
				if (destroy_mutexes(info))
					return (1);
			}
			if (info->philosophers[i].meal_counter == 0)
				j++;
		}
		if (j == info->num_of_phil)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

static int	dinner_party(t_info *info)
{
	info->start_simulation = get_time();
	if (create_threads(info))
		return (print_error_and_free(info, 4));
	if (detach_threads(info))
		return (print_error_and_free(info, 8));
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (parse_and_init(&info, argc, argv))
		return (EXIT_FAILURE);
	if (dinner_party(info))
		return (EXIT_FAILURE);
	if (death_check(info))
		return (EXIT_FAILURE);
	free_all(info, info->forks, info->philosophers);
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_info	*info;
// 	int		i;
// 	// int		philosophers;
// 	pthread_mutex_t	*ptr;

// 	info = NULL;
// 	if (parse_and_init(&info, argc, argv))
// 		return (EXIT_FAILURE);
// 	// if (create_mutexes(info))
// 	// 	return (print_error_and_free(info, 5));
// 	info->start_simulation = get_time();
// 	printf("number of philosophers - %d\n", info->num_of_phil);
// 	printf("number of_time_to meal - %d \n", info->number_of_time_to_meal);
// 	printf("time to die - %d\n", info->time_to_die);
// 	printf("time to eat - %d\n", info->time_to_eat);
// 	printf("time to sleep - %d\n", info->time_to_sleep);
// 	printf("start simulation - %lld\n", info->start_simulation);
// 	printf("timestamp - %lld\n", info->timestamp);
// 	printf("print_mutex - %p\n", &info->print);
// 	i = 0;
// 	ptr = info->forks;
// 	while (i < info->num_of_phil)
// 	{
// 		printf("fork #%d pointer - %p\n", i + 1, ptr);
// 		ptr++;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < info->num_of_phil)
// 	{
// 		printf("t_id - %d\n", info->philosophers[i].t_id);
// 		printf("death - %d\n", info->philosophers[i].death);
// 		printf("meal_counter - %d\n", info->philosophers[i].meal_counter);
// 		printf("message's address - %p\n", info->philosophers[i].message);
// 		printf("left fork pointer - %p\n", info->philosophers[i].left_fork);
// 		printf("right fork pointer - %p\n", info->philosophers[i].right_fork);
// 		printf("info's address - %p\n\n", info->philosophers[i].info);
// 		i++;
// 	}
// 	return (0);
// }
