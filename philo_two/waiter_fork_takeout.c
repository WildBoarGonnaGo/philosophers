/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_fork_takeout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:13:16 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 20:21:07 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	waiter_fork_takeout(t_philo_hands *data)
{
	sem_post(data->c_nerve->forks);
	sem_post(data->c_nerve->forks);
	data->left_hand = DROPFORK;
	data->right_hand = DROPFORK;
}
