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

t_fork_philo	*fork_philo_init_data(t_misc *misc)
{
	int				i;
	t_fork_philo	*data;

	data = (t_fork_philo *)malloc(sizeof(t_fork_philo) * misc->philo_num);
	//misc->philo_pid = (pid_t *)malloc(sizeof(pid_t) * misc->philo_num);
	if (!data)
	{
		printf("philo_three: error: system insufficient resources\n");
		return (NULL);
	}
	i = -1;
	while (++i < misc->philo_num)
	{
		data[i].left_hand = PHILO_PUT_FORK;
		data[i].right_hand = PHILO_PUT_FORK;
		data[i].misc_data = misc;
		data[i].philo_hp = misc->time_to_die;
		data[i].time_travel = 0;
		gettimeofday(&misc->cur_time, NULL);
		data[i].old_time = misc->cur_time.tv_sec * 1000 +
		misc->cur_time.tv_usec / 1000;
        data[i].num = i;
		data[i].swallow = 0;
		data[i].satiate_philo = 0;
	}
	return (data);
}