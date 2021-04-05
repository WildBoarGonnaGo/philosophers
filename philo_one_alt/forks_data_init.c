#include "philo_one.h"

void                    forks_data_init(t_forks *forks, t_time time_set)
{
	int		i;

    i = -1;
	while (++i < time_set.num_of_philo)
	    pthread_mutex_init(&forks->forks[i], NULL);
}