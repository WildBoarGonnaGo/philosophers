/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_seikatsu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:42:17 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 20:48:24 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo_seikatsu(void *data)
{
	t_philo_data	*philo_manager;

	philo_manager = (t_philo_data *)data;
	if (!(philo_manager->philo.num % 2))
		usleep(0.9 * philo_manager->misc->time_to_sleep);
	while (1)
	{
		if (!philo_routine_body(philo_manager))
			break ;
	}
	return (NULL);
}
