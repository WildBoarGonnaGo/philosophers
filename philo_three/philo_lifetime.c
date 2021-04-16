/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifetime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:43:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:55:45 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_lifetime(void *proc)
{
	pthread_t		watcher;
	t_fork_philo	*data;

	pthread_create(&watcher, NULL, check_philo_table, proc);
	pthread_detach(watcher);
	data = (t_fork_philo *)proc;
	while (loop_condition(data))
	{
		if (loop_condition(data))
			philo_preparing_to_eat(data);
		if (loop_condition(data))
			calculate_time(data, philo_is_eating,
				data->misc_data->time_to_eat);
		if (loop_condition(data))
			philo_put_forks(data);
		data->swallow
			+= (data->misc_data->num_of_time_philo_must_eat != -1);
	}
	if (data->swallow
		== data->misc_data->num_of_time_philo_must_eat)
		sem_wait(data->misc_data->swallow);
}
