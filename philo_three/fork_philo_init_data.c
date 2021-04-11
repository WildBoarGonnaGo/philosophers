/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_philo_init_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:57:35 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/11 21:26:49 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int				fork_philo_init_data(t_fork_philo *data, t_misc *misc)
{
	int	i;

	data = (t_fork_philo *)malloc(sizeof(t_fork_philo) * misc->philo_num);
	misc->philo_pid = (pid_t *)malloc(sizeof(pid_t) * misc->philo_num);
	if (!data || !misc)
	{
		printf("philo_three: error: system insufficient resources\n");
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < misc->philo_num)
	{
		data[i].left_hand = PHILO_PUT_FORK;
		data[i].right_hand = PHILO_PUT_FORK;
		data[i].misc_data = misc;
		data[i].philo_hp = misc->time_to_die;
		data[i].time_travel = 0;
		data[i].old_time = gettimeofday(&misc->chopstick, NULL);
        data[i].num = i;
	}
	return (EXIT_SUCCESS);
}