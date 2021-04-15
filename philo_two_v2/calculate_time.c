/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:11:29 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/16 01:47:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	calculate_time(t_philo_hands *data, long sleep,
			void (*starve)(t_philo_hands *, long delta))
{
	long	delta;
	long	long_old;

	long_old = data->timeflow;
	gettimeofday(&data->c_nerve->cur_time, NULL);
	data->timeflow += data->c_nerve->cur_time.tv_sec * 1000
		+ data->c_nerve->cur_time.tv_usec / 1000 - data->old_time;
	data->old_time = data->c_nerve->cur_time.tv_sec * 1000
		+ data->c_nerve->cur_time.tv_usec / 1000;
	delta = data->timeflow - long_old;
	data->dead_old_time = data->timeflow;
	usleep(sleep);
	gettimeofday(&data->c_nerve->cur_time, NULL);
	data->timeflow += data->c_nerve->cur_time.tv_sec * 1000
		+ data->c_nerve->cur_time.tv_usec / 1000 - data->old_time;
	delta += (data->c_nerve->cur_time.tv_sec * 1000
			+ data->c_nerve->cur_time.tv_usec / 1000
			- data->old_time) * 1000;
	data->old_time = data->c_nerve->cur_time.tv_sec * 1000
		+ data->c_nerve->cur_time.tv_usec / 1000;
	starve(data, delta);
}
