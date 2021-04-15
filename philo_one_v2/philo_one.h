/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:09:52 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:27:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000
# define PHDEATH 0xde

typedef unsigned int	t_uint32;
typedef unsigned short	t_uint16;

typedef struct s_time
{
	pthread_mutex_t		take_forks;
	int					num_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					number_of_time_philo_eats;
	int					error;
	int					i;
	int					detach_moveout;
}						t_time;

typedef struct s_philo
{
	pthread_t			philo_tid;
	pthread_mutex_t		simple_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_uint32			num;
	struct timeval		cur_time;
	long				time_travel;
	long				old_time;
	long				philo_hp;
	int					ranchi_indx;
	long				dead_old_time;
}						t_philo;

typedef struct s_philo_data
{
	t_philo				philo;
	t_time				*misc;
}						t_philo_data;

t_uint16				wb_atoi(char *str, t_uint16 res, int flags);
void					philo_data_init(t_philo_data *philo, t_uint32 num);
void					time_data_proc_init(t_time *time_input,
							int argc, char *argv[]);
void					philo_is_eating(t_philo_data *philo_data, long delta);
void					philo_is_sleeping(t_philo_data *philo_data, long delta);
void					philo_takes_fork(t_philo_data *philo_data, long delta);
void					calculate_time(t_philo_data *data, long sleep,
							void (*starve)(t_philo_data *, long delta));
void					*philo_seikatsu(void *data);
t_philo_data			*num_of_philo_init(t_time *time_set);
void					*philo_ranchi(void *data);
void					memfree_alloc(void **addr);
t_philo_data			*num_of_philo_init(t_time *time_set);
void					case_handle(t_time *time_set,
							t_philo_data *philo_data_set);
void					check_if_dish_life(t_time *time_set,
							t_philo_data *philo_data_set);
int						philo_routine_body(t_philo_data *philo_manager);
void					philo_is_thinking(t_philo_data *philo_data,
							long delta);

#endif
