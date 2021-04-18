/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:27:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/18 10:27:53 by lchantel         ###   ########.fr       */
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
			sem_wait(checker->misc_data->msg);
			sem_wait(checker->misc_data->dead_philo);
			printf("%ld %d died\n", checker->time_travel
				+ checker->philo_hp / 1000, checker->num + 1);
				//--checker->misc_data->is_dead;
			/*if (loop_condition(checker))
			{
			}*/
			return (NULL);
		}
	}			
	return (NULL);
}
