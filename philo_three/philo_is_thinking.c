/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:03:22 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/19 20:48:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_is_thinking(t_fork_philo *crnl, long diff_time,
			long old_time)
{
	crnl->philo_hp -= diff_time;
	if (crnl->philo_hp > 0 && crnl->misc_data->msg->__size[0])
	{
		sem_wait(crnl->misc_data->msg);
		if (loop_condition(crnl))
			printf("%ld %d is thinking\n", old_time, crnl->num + 1);
		sem_post(crnl->misc_data->msg);
	}
}
