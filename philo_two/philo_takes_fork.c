/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_takes_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:12:56 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 19:58:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	philo_takes_fork(t_philo_hands *philo_data, long delta)
{
	philo_data->philo_hp -= delta;
	if (philo_data->philo_hp <= 0)
	{
		sem_wait(philo_data->c_nerve->death);
		sem_wait(philo_data->c_nerve->msg);
		printf("%ld %d died\n", philo_data->dead_old_time
			+ philo_data->philo_hp / 1000,
			philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
	sem_wait(philo_data->c_nerve->msg);
	printf("%ld %d has taken a fork\n",
		philo_data->dead_old_time, philo_data->num + 1);
	sem_post(philo_data->c_nerve->msg);
}
