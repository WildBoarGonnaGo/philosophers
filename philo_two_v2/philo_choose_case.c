#include "philo_two.h"

void					philo_choose_case(void *(*good_day)(void *),
						t_philo_hands *data/*, pthread_t *thread_id*/)
{

	data->c_nerve->indx = -1;
	while (++data->c_nerve->indx < data->c_nerve->philo_num)
	{
		printf("stop moment\n");
		pthread_create(/*thread_id + data->c_nerve->indx*/&data[data->c_nerve->indx].philo_tid,
		NULL, good_day, (void *)&data[data->c_nerve->indx]);
		//pthread_detach(/**(thread_id + data->c_nerve->indx)*/data[data->c_nerve->indx].philo_tid);
		if (data[data->c_nerve->indx].c_nerve->num_of_time_philo_must_eat == -1)
			pthread_detach(/**(thread_id + data->c_nerve->indx)*/data[data->c_nerve->indx].philo_tid);
	}
}