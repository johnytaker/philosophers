/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_of_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:13:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/03 19:09:39 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks_and_eat(t_philosopher *philo)
{
	sem_wait(philo->info->forks);
	print_action(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	ft_time(philo->time_to_eat);
	update_last_meal(philo);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	start_sleeping(t_philosopher *philo)
{
	print_action(philo, "is sleeping");
	ft_time(philo->time_to_sleep);
}

void	start_thinking(t_philosopher *philo)
{
	print_action(philo, "is thinking");
}
