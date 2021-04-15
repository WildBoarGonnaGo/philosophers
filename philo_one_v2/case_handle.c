/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:11:00 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:22:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	case_handle(t_time *time_set, t_philo_data *philo_data_set)
{
	if (time_set->number_of_time_philo_eats == -1)
	{
		while (++time_set->i < time_set->num_of_philo)
		{
			pthread_create(&philo_data_set[time_set->i].philo.philo_tid, NULL,
				philo_seikatsu, (void *)&philo_data_set[time_set->i]);
			pthread_detach(philo_data_set[time_set->i].philo.philo_tid);
		}
	}
	else
	{
		while (++time_set->i < time_set->num_of_philo)
		{
			philo_data_set[time_set->i].philo.ranchi_indx = 0;
			pthread_create(&philo_data_set[time_set->i].philo.philo_tid, NULL,
				philo_ranchi, (void *)&philo_data_set[time_set->i]);
		}
	}
}
