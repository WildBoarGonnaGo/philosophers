#include "philo_three.h"

int				calculate_time(t_fork_philo *data, 
				int (*func)(t_fork_philo *, long, long), long time)
{
	long	diff_time;
	long 	old_time;

	old_time = data->time_travel;
	usleep(time);
	gettimeofday(&data->misc_data->cur_time, NULL);
	diff_time = data->misc_data->cur_time.tv_sec * 1000 +
	data->misc_data->cur_time.tv_usec / 1000 - data->old_time ;
	data->dead_old_time = old_time;
	data->old_time = data->misc_data->cur_time.tv_sec * 1000 +
	data->misc_data->cur_time.tv_usec / 1000;
	data->time_travel += diff_time;
	return (func(data, diff_time, data->dead_old_time));
}