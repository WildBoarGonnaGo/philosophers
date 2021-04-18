/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:18:27 by lchantel          #+#    #+#             */
/*   Updated: 2021/04/18 09:06:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	calculate_time(t_fork_philo *data,
			void (*func)(t_fork_philo *, long, long), long time)
{
	long	diff_time;

	gettimeofday(&data->misc_data->cur_time, NULL);
	data->time_travel += data->misc_data->cur_time.tv_sec * 1000
		+ data->misc_data->cur_time.tv_usec / 1000
		- data->old_time;
	diff_time = (data->misc_data->cur_time.tv_sec * 1000
			+ data->misc_data->cur_time.tv_usec / 1000
			- data->old_time) * 1000;
	data->old_time = data->misc_data->cur_time.tv_sec * 1000
		+ data->misc_data->cur_time.tv_usec / 1000;
	data->dead_old_time = data->time_travel;
	usleep(time);
	gettimeofday(&data->misc_data->cur_time, NULL);
	data->time_travel += data->misc_data->cur_time.tv_sec * 1000
		+ data->misc_data->cur_time.tv_usec / 1000
		- data->old_time;
	diff_time += (data->misc_data->cur_time.tv_sec * 1000
			+ data->misc_data->cur_time.tv_usec / 1000
			- data->old_time) * 1000;
	data->old_time = data->misc_data->cur_time.tv_sec * 1000
		+ data->misc_data->cur_time.tv_usec / 1000;
	func(data, diff_time, data->dead_old_time);
}
