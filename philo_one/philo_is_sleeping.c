/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:33:21 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 18:25:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_is_sleeping(t_philo_data *philo_data, long delta)
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
	printf("%ld %d is sleeping\n", philo_data->philo.dead_old_time,
		philo_data->philo.num + 1);
	pthread_mutex_unlock(&philo_data->misc->msg);
}
