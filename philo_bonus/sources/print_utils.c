/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:58:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/01 02:00:21 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_error_and_exit(int flag)
{
	if (flag == 1)
		print_usage();
	else if (flag == 2)
		printf("Memory allocation error\n");
	else if (flag == 3)
		printf("Use positive digits > 0 in MAX_INT range only!\n");
	else if (flag == 4)
		printf("process create error\n");
	else if (flag == 5)
		printf("sem_unlink error\n");
	else if (flag == 6)
		printf("sem_open error\n");
	else if (flag == 7)
		printf("sem_wait error\n");
	else if (flag == 8)
		printf("sem_post error\n");
	else if (flag == 9)
		printf("pthread_create error\n");
	else if (flag == 10)
		printf("pthread_detach error\n");
	else if (flag ==11)
		printf("waitpid error\n");
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	printf("\n  USAGE:\n\n\
  ./philo [1] [2] [3] [4] [*5] \n\n\
   1 > number_of_philosophers (from 1 to 200)\n\
   2 > time_to_die (milliseconds) (from 1 to MAX_INT)\n\
   3 > time_to_eat (milliseconds) (from 1 to MAX_INT)\n\
   4 > time_to_sleep(milliseconds) (from 1 to MAX_INT)\n\
 * 5 > number_of_times_each_philosopher_must_eat (from 1 to MAX_INT)\n");
}

void	print_action(t_philosopher *phil, char *str)
{
	if (sem_wait(phil->info->print))
		print_error_and_exit(7);
	update_timestamp(phil->info);
	printf("%lld %d %s\n", \
		phil->info->timestamp, phil->philo_id, str);
	if (sem_post(phil->info->print))
		print_error_and_exit(8);
}
