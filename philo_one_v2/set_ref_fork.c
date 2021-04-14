/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ref_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:00:45 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/15 00:29:33 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	set_ref_fork(t_philo_data *ref_philo, t_time
			*time_set, int indx)
{
	struct timeval	temp;

	memset((void *)&ref_philo[indx], 0, sizeof(t_philo_data) - 1);
	ref_philo[indx].misc = time_set;
	ref_philo[indx].philo.num = indx;
	if (time_set->num_of_philo == 2)
	{
		ref_philo[indx].philo.left_fork = &ref_philo[indx
			% time_set->num_of_philo].philo.simple_fork;
		ref_philo[indx].philo.right_fork = &ref_philo[(indx + 1)
			% time_set->num_of_philo].philo.simple_fork;
	}
	else
	{
		ref_philo[indx].philo.left_fork = &ref_philo[(indx + 1)
			% (time_set->num_of_philo)].philo.simple_fork;
		ref_philo[indx].philo.right_fork
			= &ref_philo[(indx + time_set->num_of_philo - 1)
			% (time_set->num_of_philo)].philo.simple_fork;
	}
	ref_philo[indx].philo.time_travel = 0;
	gettimeofday(&temp, NULL);
	ref_philo[indx].philo.old_time = temp.tv_sec * 1000
		+ temp.tv_usec / 1000;
	ref_philo[indx].philo.philo_hp = time_set->time_to_die;
}

t_philo_data	*num_of_philo_init(t_time *time_set)
{
	t_philo_data	*data;
	int				i;

	data = (t_philo_data *)malloc(sizeof(t_philo_data)
			* time_set->num_of_philo);
	if (!data)
		return (NULL);
	time_set->error = 0;
	i = -1;
	while (++i < time_set->num_of_philo)
		set_ref_fork(data, time_set, i);
	i = -1;
	while (++i < time_set->num_of_philo)
		pthread_mutex_init(&data[i].philo.simple_fork, NULL);
	return (data);
}
