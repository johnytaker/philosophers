/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:35:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/27 21:13:24 by iugolin          ###   ########.fr       */
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

/*					RETURN_CODES					*/
# define RETURN_SUCCESS	0
# define RETURN_FAILURE	1
/*					STRUCTURES						*/
typedef struct s_philosopher	t_philosopher;
typedef struct s_info			t_info;

struct s_philosopher
{
	pthread_t		thread;
	int				t_id;
	int				death;
	int				meal_counter;
	long long		last_meal;
	pthread_mutex_t	fork;
	pthread_mutex_t	*message;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info			*info;
};

struct s_info
{
	int				num_of_phil;
	int				number_of_time_to_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		start_simulation;
	long long		timestamp;
	pthread_mutex_t	print;
	t_philosopher	*philosophers;
};
/*					ALLOCATION_UTILS				*/
int			memory_allocation(t_info **info);
int			free_all(t_info *info, t_philosopher *philosophers);
/*					EXECUTION						*/
void		*execution(void *philosopher);
/*					FT_ATOI							*/
int			ft_isdigit(int c);
int			ft_atoi_unsigned(const char *str);
/*					PARSE_AND_INIT					*/
int			parse_and_init(t_info **info, int argc, char **argv);
/*					PRINT_UTILS						*/
int			print_error_and_free(t_info	*info, int flag);
void		print_usage(void);
int			print_action(t_philosopher *phil, char *str);
/*						TIME						*/
long long	get_time(void);
void		update_timestamp(t_info *info);
void		update_last_meal(t_philosopher *philo);
void		ft_time(int time);
/*					THREAD_UTILS					*/
int			create_threads(t_info *info);
int			detach_threads(t_info *info);
int			destroy_mutexes(t_info *info);
/*					TYPES_OF_ACTIONS					*/
void		take_forks_and_eat(t_philosopher *phil);
void		start_sleeping(t_philosopher *phil);
void		start_thinking(t_philosopher *phil);

#endif
