/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:35:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/14 22:30:54 by iugolin          ###   ########.fr       */
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
typedef struct s_info			t_info;

struct s_philosopher
{
	pthread_t				thread;
	int						t_id;
	int						meal_counter;
	long long				start_simulation;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
};

struct s_info
{
	int				num_of_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_to_meal;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
};

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

t_info	*parse_and_init(int argc, char **argv);

void	print_error(char *str);
void	print_memory_error(void);
void	print_usage(void);

#endif
