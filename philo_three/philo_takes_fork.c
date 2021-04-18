/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_takes_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:49:20 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/18 21:19:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_takes_fork(t_fork_philo *crnl, long diff_time,
			long old_time)
{
	crnl->philo_hp -= diff_time;
	if (crnl->philo_hp > 0)
	{
		sem_wait(crnl->misc_data->msg);
		if (loop_condition(crnl))
			printf("%ld %d has taken a fork\n", old_time, crnl->num + 1);
		sem_post(crnl->misc_data->msg);
	}
}
