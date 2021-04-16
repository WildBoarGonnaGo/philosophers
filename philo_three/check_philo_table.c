/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:27:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 02:42:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*check_philo_table(void *data)
{
	t_fork_philo	*checker;

	checker = (t_fork_philo *)data;
	while (1)
	{
		if (checker->philo_hp <= 0)
		{
			sem_wait(checker->misc_data->dead_philo);
			sem_wait(checker->misc_data->msg);
			printf("%ld %d died\n", checker->time_travel
				+ checker->philo_hp / 1000, checker->num + 1);
			sem_post(checker->misc_data->msg);
			return (NULL);
		}
	}			
	return (NULL);
}
