#include "philo_two.h"

void					philo_choose_case(void *(*good_day)(void *),
						t_philo_hands *data, pthread_t *thread_id)
{
	while (++data->c_nerve->indx < data->c_nerve->philo_num)
	{
		pthread_create(thread_id + data->c_nerve->indx, NULL,
		good_day, (void *)&data[data->c_nerve->indx]);
		pthread_detach(*(thread_id + data->c_nerve->indx));
	}
}