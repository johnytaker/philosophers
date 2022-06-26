/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:12:50 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/26 21:16:45 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*execution(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (philo->meal_counter)
	{
		take_forks_and_eat(philo);
		start_sleeping(philo);
		start_thinking(philo);
		if (philo->meal_counter > 0)
			philo->meal_counter--;
	}
	return (NULL);
}
