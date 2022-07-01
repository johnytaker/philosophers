/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:12:50 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/01 02:09:17 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*death_check(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	// printf("watchman\n");
	while (1)
	{
		update_timestamp(philo->info);
		philo->death = \
			philo->info->timestamp - philo->last_meal;
		if (philo->death > philo->info->time_to_die)
		{
			print_action(philo, "died");
			exit(EXIT_SUCCESS);
		}
		if (philo->meal_counter == 0)
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	execution(t_philosopher *philo)
{
	pthread_t	watchman;

	if (pthread_create(&watchman, NULL, death_check, &philo))
		print_error_and_exit(9);
	if (philo->pid % 2)
		usleep(15000);
	if (pthread_detach(watchman))
		print_error_and_exit(10);
	while (philo->meal_counter)
	{
		take_forks_and_eat(philo);
		start_sleeping(philo);
		start_thinking(philo);
		if (philo->meal_counter > 0)
			philo->meal_counter--;
	}
	printf("finish\n");
	exit(EXIT_SUCCESS);
}
