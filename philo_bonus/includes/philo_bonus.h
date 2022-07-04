/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:35:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/07/04 11:15:52 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>

/*					RETURN_CODES								*/
# define RETURN_SUCCESS	0
# define RETURN_FAILURE	1
/*					STRUCTURES									*/
typedef struct s_philosopher	t_philosopher;
typedef struct s_info			t_info;

struct s_philosopher
{
	pid_t			pid;
	int				philo_id;
	int				death_counter;
	int				meal_counter;
	long long		last_meal;
	long long		timestamp;
	long long		start_time;
	t_info			*info;
};

struct s_info
{
	int				num_of_phil;
	int				number_of_time_to_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*data;
	t_philosopher	*philosophers;
};
/*					ALLOCATION_UTILS							*/
int			memory_allocation(t_info **info);
int			free_all(t_info *info, t_philosopher *philosophers);
/*					EXECUTION									*/
void		execution(t_philosopher *philo);
/*					FT_ATOI										*/
int			ft_isdigit(int c);
int			ft_atoi_unsigned(const char *str);
/*					PARSE_AND_INIT								*/
void		parse_and_init(t_info **info, int argc, char **argv);
/*					PRINT_UTILS									*/
void		print_error_and_exit(int flag);
void		print_usage(void);
void		print_action(t_philosopher *phil, char *str);
/*					PROCESS_UTILS								*/
void		wait_and_kill(t_info *info);
void		create_all_processes(t_info *info);
/*					SEMAPHORE_UTILS								*/
void		unlink_semaphores(void);
void		open_semaphores(t_info *info);
void		close_semaphores(t_info *info);
/*						TIME									*/
long long	get_time(void);
void		update_timestamp(t_philosopher *philo);
void		update_last_meal(t_philosopher *philo);
void		update_death_counter(t_philosopher *philo);
void		ft_time(int time);
/*					TYPES_OF_ACTIONS							*/
void		take_forks_and_eat(t_philosopher *philo);
void		start_sleeping(t_philosopher *philo);
void		start_thinking(t_philosopher *philo);

#endif
