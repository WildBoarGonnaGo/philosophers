/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:09:20 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/18 09:06:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	fork_proc(t_misc *misc_data, t_fork_philo *philo_proc)
{
	int	i;

	i = -1;
	while (++i < misc_data->philo_num)
	{
		philo_proc[i].philo_pid = fork();
		if (!philo_proc[i].philo_pid)
		{
			philo_lifetime(&philo_proc[i]);
			exit(0);
		}
	}
}
