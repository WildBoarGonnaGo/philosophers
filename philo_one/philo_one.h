/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:35:51 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/28 23:20:44 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define ZERO 0b0001
# define PLUSMINUS 0b0010
# define SPACE 0b0100
# define SUBZERO 0b1000

typedef unsigned short	uint16;
typedef	unsigned int	uint32;
//typedef long			millseconds;

typedef	struct			s_philo_one
{
	uint16			num_of_philo;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	int				num_times_philo_eat;
	struct timeval	time_val;
	//struct timezone	*time_zone;
	uint16			num_fork;
	pthread_t		*philo;
	pthread_mutex_t	*chopstick;
	int				indx[2];
	int				error[5];
	int				*starvation;
	long			*time_travel;
	long			*old_time;
	//long			*prefix;
}						t_philo_one;

uint16					wb_atoi(char *str, uint16 res, int flags);

#endif
