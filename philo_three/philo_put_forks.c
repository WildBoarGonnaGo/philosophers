/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_put_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:49:29 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 20:31:58 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_put_forks(t_fork_philo *philo)
{
	sem_post(philo->misc_data->chopstick);
	sem_post(philo->misc_data->chopstick);
	calculate_time(philo, philo_is_sleeping,
		philo->misc_data->time_to_sleep);
	calculate_time(philo, philo_is_thinking, 0);
}
