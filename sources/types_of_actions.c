/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_of_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:13:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/27 21:54:29 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks_and_eat(t_philosopher *phil)
{
	pthread_mutex_lock(phil->left_fork);
	print_action(phil, "has taken a fork");
	pthread_mutex_lock(phil->right_fork);
	print_action(phil, "has taken a fork");
	print_action(phil, "is eating");
	ft_time(phil->info->time_to_eat);
	update_last_meal(phil);
	pthread_mutex_unlock(phil->left_fork);
	pthread_mutex_unlock(phil->right_fork);
}

void	start_sleeping(t_philosopher *phil)
{
	print_action(phil, "is sleeping");
	ft_time(phil->info->time_to_sleep);
}

void	start_thinking(t_philosopher *phil)
{
	print_action(phil, "is thinking");
}
