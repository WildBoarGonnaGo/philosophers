/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_body.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:40:16 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 00:19:01 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	philo_routine_body(t_philo_data *philo_manager)
{
	pthread_mutex_lock(&philo_manager->misc->take_forks);
	pthread_mutex_lock(philo_manager->philo.left_fork);
	calculate_time(philo_manager, 0, philo_takes_fork);
	if (philo_manager->misc->error)
		return (0);
	pthread_mutex_unlock(&philo_manager->misc->take_forks);
	pthread_mutex_lock(philo_manager->philo.right_fork);
	calculate_time(philo_manager, 0, philo_takes_fork);
	if (philo_manager->misc->error)
		return (0);
	calculate_time(philo_manager, philo_manager->misc->time_to_eat,
		philo_is_eating);
	if (philo_manager->misc->error)
		return (0);
	pthread_mutex_unlock(philo_manager->philo.right_fork);
	pthread_mutex_unlock(philo_manager->philo.left_fork);
	calculate_time(philo_manager, philo_manager->misc->time_to_sleep,
		philo_is_sleeping);
	if (philo_manager->misc->error)
		return (0);
	return (1);
}
