/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:30:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/14 23:25:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	calculate_time(t_philo_data *data, long sleep,
		void (*starve)(t_philo_data *, long delta))
{
	long	delta;

	usleep(sleep);
	data->philo.dead_old_time = data->philo.time_travel;
	gettimeofday(&data->philo.cur_time, NULL);
	data->philo.time_travel += data->philo.cur_time.tv_sec * 1000
		+ data->philo.cur_time.tv_usec / 1000 - data->philo.old_time;
	delta = (data->philo.cur_time.tv_sec * 1000
			+ data->philo.cur_time.tv_usec / 1000
			- data->philo.old_time) * 1000;
	data->philo.old_time = data->philo.cur_time.tv_sec * 1000
		+ data->philo.cur_time.tv_usec / 1000;
	starve(data, delta);
}
