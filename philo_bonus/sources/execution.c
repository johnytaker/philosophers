/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:12:50 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/03 20:13:22 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


static void	*death_check(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (1)
	{
		update_timestamp(philo);
		update_death_counter(philo);
		// printf("timestamp - %lld\ndeathcounter - %d\n", philo->timestamp, philo->death_counter);
		// printf("last meal - %lld\n", philo->last_meal);
		// sem_wait(philo->info->data);
		if (philo->death_counter >= philo->time_to_die)
		{
			print_action(philo, "died");
			philo->death_flag = 1;
			exit(EXIT_FAILURE);
		}
		if (philo->meal_counter == 0)
			break ;
		// sem_post(philo->info->data);
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
	exit(EXIT_SUCCESS);
}
