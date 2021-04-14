#include "philo_one.h"

void					calculate_time(t_philo_data *data, long sleep,
						void (*starve)(t_philo_data *, long delta))
{
	long delta;

	usleep(sleep);
	data->philo.dead_old_time = data->philo.time_travel;
	gettimeofday(&data->philo.cur_time, NULL);
	data->philo.time_travel += data->philo.cur_time.tv_sec * 1000 +
	/*return_usec_round(data->philo->cur_time.tv_usec)*/
	data->philo.cur_time.tv_usec / 1000 - data->philo.old_time;
	delta = (data->philo.cur_time.tv_sec * 1000 +
	/*return_usec_round(data->philo->cur_time.tv_usec)*/ data->philo.cur_time.tv_usec / 1000
	- data->philo.old_time) * 1000;
	data->philo.old_time = data->philo.cur_time.tv_sec * 1000 +
    /*return_usec_round(data->philo->cur_time.tv_usec)*/
	data->philo.cur_time.tv_usec / 1000;
	starve(data, delta);
}