/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dish_life.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:22:16 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:22:11 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	check_if_dish_life(t_time *time_set, t_philo_data *philo_data_set)
{
	if (time_set->number_of_time_philo_eats != -1)
	{
		time_set->i = -1;
		while (++time_set->i < time_set->num_of_philo)
			pthread_join(philo_data_set[time_set->i].philo.philo_tid, NULL);
	}
	else
	{
		while (1)
		{
			if (time_set->error)
				break ;
		}
	}
}
