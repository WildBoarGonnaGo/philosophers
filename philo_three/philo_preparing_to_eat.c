/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_preparing_to_eat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:49:37 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 23:01:40 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_preparing_to_eat(t_fork_philo *philo)
{
	/*if (philo->left_hand == PHILO_PUT_FORK)
	{
		sem_wait(philo->misc_data->waiter);
		sem_wait(philo->misc_data->chopstick);
		calculate_time(philo, philo_takes_fork, 0);
		philo->left_hand = PHILO_TAKE_FORK;
	}
	if (philo->right_hand == PHILO_PUT_FORK)
	{
		sem_wait(philo->misc_data->chopstick);
		calculate_time(philo, philo_takes_fork, 0);
		philo->right_hand = PHILO_TAKE_FORK;
	}*/
	sem_wait(philo->misc_data->waiter);
	sem_wait(philo->misc_data->chopstick);
	calculate_time(philo, philo_takes_fork, 0);
	//philo->left_hand = PHILO_TAKE_FORK;
	sem_wait(philo->misc_data->chopstick);
	calculate_time(philo, philo_takes_fork, 0);
	//philo->right_hand = PHILO_TAKE_FORK;
	sem_post(philo->misc_data->waiter);
}
