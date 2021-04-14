/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ranchi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:42:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 00:15:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo_ranchi(void *data)
{
	t_philo_data	*philo_manager;

	philo_manager = (t_philo_data *)data;
	philo_manager->philo.ranchi_indx = -1;
	while (++philo_manager->philo.ranchi_indx
		< philo_manager->misc->number_of_time_philo_eats)
	{
		if (!philo_routine_body(philo_manager))
			break ;
	}
	return (NULL);
}
