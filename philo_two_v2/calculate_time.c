#include "philo_two.h"

void					calculate_time(t_philo_hands *data, long sleep,
						void (*starve)(t_philo_hands *, long delta))
{
	long delta;

	usleep(sleep);
	gettimeofday(&data->c_nerve->cur_time, NULL);
	data->timeflow += data->c_nerve->cur_time.tv_sec * 1000 +
	data->c_nerve->cur_time.tv_usec / 1000 - data->old_time;
	delta = (data->c_nerve->cur_time.tv_sec * 1000 +
	data->c_nerve->cur_time.tv_usec / 1000 - data->old_time) * 1000;
	data->old_time = data->c_nerve->cur_time.tv_sec * 1000 +
    data->c_nerve->cur_time.tv_usec / 1000;
	starve(data, delta);
}