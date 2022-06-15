/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:58:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/14 22:37:39 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	print_memory_error(void)
{
	printf("Allocate memory error\n");
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	printf("\n  USAGE:\n\n\
  ./philo [1] [2] [3] [4] [*5] \n\n\
   1 > number_of_philosophers (no more than 200)\n\
   2 > time_to_die (milliseconds)\n\
   3 > time_to_eat (milliseconds)\n\
   4 > time_to_sleep(milliseconds)\n\
 * 5 > number_of_times_each_philosopher_must_eat\n");
	exit(EXIT_FAILURE);
}
