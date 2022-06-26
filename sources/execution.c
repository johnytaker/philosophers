/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:12:50 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 20:58:12 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*execution(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (philo->meal_counter)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken the left fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken the right fork");
		take_forks_and_eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		start_sleeping(philo);
		start_thinking(philo);
		if (philo->meal_counter > 0)
			philo->meal_counter--;
	}
	return (NULL);
}
