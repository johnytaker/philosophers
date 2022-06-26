/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:58:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 21:15:43 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error_and_free(t_info	*info, int flag)
{
	if (flag == 1)
		print_usage();
	else if (flag == 2)
		printf("Memory allocation error\n");
	else if (flag == 3)
		printf("Use positive digits in MAX_INT range only!\n");
	else if (flag == 4)
		printf("pthread_create error\n");
	else if (flag == 5)
		printf("pthread_mutex_init error\n");
	else if (flag == 6)
		printf("pthread_mutex_lock error\n");
	else if (flag == 7)
		printf("pthread_mutex_unlock error\n");
	else if (flag == 8)
		printf("pthread_detach error\n");
	else if (flag == 9)
		printf("pthread_mutex_destroy error\n");
	return (free_all(info, info->forks, info->philosophers));
}

void	print_usage(void)
{
	printf("\n  USAGE:\n\n\
  ./philo [1] [2] [3] [4] [*5] \n\n\
   1 > number_of_philosophers (from 1 to 200)\n\
   2 > time_to_die (milliseconds)\n\
   3 > time_to_eat (milliseconds)\n\
   4 > time_to_sleep(milliseconds)\n\
 * 5 > number_of_times_each_philosopher_must_eat\n");
}

void	print_action(t_philosopher *phil, char *str)
{
	pthread_mutex_lock(&phil->info->print);
	update_timestamp(phil->info);
	printf("%lld %d %s\n", \
		phil->info->timestamp, phil->t_id, str);
	pthread_mutex_unlock(&phil->info->print);
}
