/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:40:30 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/17 19:37:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_is_eating(t_fork_philo *crnl, long diff_time,
			long old_time)
{
	crnl->philo_hp = crnl->misc_data->time_to_die
		- diff_time;
	if (crnl->philo_hp > 0)
	{
		sem_wait(crnl->misc_data->msg);
		if (loop_condition(crnl))
			printf("%ld %d is eating\n", old_time, crnl->num + 1);
		sem_post(crnl->misc_data->msg);
	}
}
