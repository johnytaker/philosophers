/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_of_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:13:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/04 11:02:07 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks_and_eat(t_philosopher *philo)
{
	if (sem_wait(philo->info->forks))
		print_error_and_exit(6);
	print_action(philo, "has taken a fork");
	if (sem_wait(philo->info->forks))
		print_error_and_exit(6);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	ft_time(philo->info->time_to_eat);
	if (sem_post(philo->info->forks))
		print_error_and_exit(7);
	if (sem_post(philo->info->forks))
		print_error_and_exit(7);
	update_last_meal(philo);
}

void	start_sleeping(t_philosopher *philo)
{
	print_action(philo, "is sleeping");
	ft_time(philo->info->time_to_sleep);
}

void	start_thinking(t_philosopher *philo)
{
	print_action(philo, "is thinking");
}
