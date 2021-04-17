/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:33:06 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 19:57:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_is_eating(t_philo_data *philo_data, long delta)
{
	philo_data->philo.philo_hp = philo_data->misc->time_to_die - delta;
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
	printf("%ld %d is eating\n", philo_data->philo.dead_old_time,
		philo_data->philo.num + 1);
	pthread_mutex_unlock(&philo_data->misc->msg);
}
