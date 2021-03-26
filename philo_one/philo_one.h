/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:35:51 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/25 20:55:13 by lchantel         ###   ########.fr       */
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



typedef	struct			s_philo_one
{
	uint16			num_of_philo;
	uint16			time_to_die;
	uint16			time_to_eat;
	uint16			num_times_philo_eat;
	struct timeval	time_info;
	uint16			num_fork;
	pthread_t		*plan;
	pthread_mutex_t	*chopstick;
	int				indx[2];
}						t_philo_one;

int						wb_atoi(char *str, int res, int flags);


#endif
