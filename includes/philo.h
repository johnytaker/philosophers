/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:35:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/13 18:50:20 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_philosopher	t_philosopher;
typedef struct s_fork			t_fork;
typedef struct s_data			t_data;

struct s_philosopher
{
	pthread_t		thread;
	int				t_id;
	int				meal_counter;
	long long		start_simulation;
	pthread_mutex_t	*left_fork;
	pthread_mutex_			*right_fork;
	t_data			*data;
};

struct s_fork
{
	int				fork_id;
	pthread_mutex_t	mutex;
	t_philosopher	*current_owner;
};

struct s_data
{
	int				num_of_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_to_meal;
	t_philosopher	*philosophers;
	t_fork			*forks;
};

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

t_data	*parser(int argc, char **argv);

void	ft_putstr(char *str);
void	error(char *str);

#endif