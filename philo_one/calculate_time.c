/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:30:14 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 20:08:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	calculate_time(t_philo_data *data, long sleep,
			void (*starve)(t_philo_data *, long delta))
{
	long	delta;

	gettimeofday(&data->philo.cur_time, NULL);
	data->philo.time_travel += data->philo.cur_time.tv_sec * 1000
		+ data->philo.cur_time.tv_usec / 1000 - data->philo.old_time;
	delta = (data->philo.cur_time.tv_sec * 1000
			+ data->philo.cur_time.tv_usec / 1000
			- data->philo.old_time) * 1000;
	data->philo.old_time = data->philo.cur_time.tv_sec * 1000
		+ data->philo.cur_time.tv_usec / 1000;
	data->philo.dead_old_time = data->philo.time_travel;
	usleep(sleep);
	gettimeofday(&data->philo.cur_time, NULL);
	data->philo.time_travel += data->philo.cur_time.tv_sec * 1000
		+ data->philo.cur_time.tv_usec / 1000 - data->philo.old_time;
	delta += (data->philo.cur_time.tv_sec * 1000
			+ data->philo.cur_time.tv_usec / 1000
			- data->philo.old_time) * 1000;
	data->philo.old_time = data->philo.cur_time.tv_sec * 1000
		+ data->philo.cur_time.tv_usec / 1000;
	starve(data, delta);
}
