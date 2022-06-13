/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:42:14 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/13 18:47:06 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*parser(int argc, char **argv)
{
	t_data	*data;
	
	if (argc == 5 || argc == 6)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			error("Allocate memory error\n");
		data->num_of_phil = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			data->number_of_time_to_meal = ft_atoi(argv[5]);
		data->forks = 
	}
	else
		error("Wrong number of arguments\n");
	return (data);
}

t_fork	*init_fork(t_data *data, int fork_id)
{
	t_fork	*fork;
	pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	fork = (t_fork *)malloc(sizeof(t_fork));
	fork->fork_id = fork_id;
	fork->mutex = ;
	fork->current_owner = NULL;
	return (fork);
}

t_philosopher	*init_philosopher(t_data *data, int thread_id)
{
	t_philosopher	*philosopher;
	
	philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
	philosopher->t_id = thread_id;	
	philosopher->data = data;
	philosopher->right_fork = 
	philosopher->meal_counter = 0;
}
