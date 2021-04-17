/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_takes_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:42:36 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 18:50:53 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_takes_fork(t_philo_data *philo_data, long delta)
{
	philo_data->philo.philo_hp -= delta;
	if (philo_data->philo.philo_hp <= 0)
	{
		pthread_mutex_lock(&philo_data->misc->msg);
		printf("%ld %d died\n", philo_data->philo.time_travel
			+ philo_data->philo.philo_hp / 1000,
			philo_data->philo.num + 1);
		philo_data->misc->error = PHDEATH;
		return ;
	}
	pthread_mutex_lock(&philo_data->misc->msg);
	printf("%ld %d has taken a fork\n",
		philo_data->philo.dead_old_time,
		philo_data->philo.num + 1);
	pthread_mutex_unlock(&philo_data->misc->msg);
}
