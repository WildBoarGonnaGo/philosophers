/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:40:36 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 02:42:07 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_is_sleeping(t_fork_philo *crnl, long diff_time,
			long old_time)
{
	sem_wait(crnl->misc_data->msg);
	if (loop_condition(crnl))
		printf("%ld %d is sleeping\n", old_time, crnl->num + 1);
	sem_post(crnl->misc_data->msg);
	printf("philo_hp[%d] = %ld\n", crnl->num, crnl->philo_hp);
	printf("diff_time = %ld\n", diff_time);
	crnl->philo_hp -= diff_time;
}
