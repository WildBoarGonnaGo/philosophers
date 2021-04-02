#include "philo_one.h"

void					calculate_time(t_philo_data *data, useconds_t sleep,
						void (*starve)(t_philo_data *))
{
	usleep(sleep);
	gettimeofday(&data->philo->cur_time, NULL);
	data->philo->time_travel += data->philo->cur_time.tv_sec * 1000 +
	return_usec_round(data->philo->cur_time.tv_usec) - data->philo->old_time;
	data->philo->old_time = data->philo->cur_time.tv_sec * 1000 +
    return_usec_round(data->philo->cur_time.tv_usec);
	starve(data);
}