/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:37:30 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:25:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_is_thinking(t_philo_data *philo_data, long delta)
{
	printf("%ld %d is thinking\n", philo_data->philo.dead_old_time,
		philo_data->philo.num + 1);
	philo_data->philo.philo_hp -= delta;
	if (philo_data->philo.philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->philo.time_travel
			+ philo_data->philo.philo_hp / 1000,
			philo_data->philo.num + 1);
		philo_data->misc->error = PHDEATH;
	}
}
