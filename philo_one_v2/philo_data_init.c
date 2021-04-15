/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:30:56 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 22:09:37 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_data_init(t_philo_data *philo, t_uint32 num)
{
	struct timeval	temp;
	int				indx;

	indx = (num + 1) % philo->misc->num_of_philo;
	philo->philo.left_fork = &philo[indx].philo.simple_fork;
	gettimeofday(&temp, NULL);
	philo->philo.time_travel = 0;
	philo->philo.old_time = temp.tv_sec * 1000 + temp.tv_usec / 1000;
}
