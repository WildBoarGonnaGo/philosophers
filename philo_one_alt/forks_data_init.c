#include "philo_one.h"

void                    forks_data_init(t_forks *forks, t_time time_set)
{
	int		i;
    //t_forks	*forks_data;

    i = -1;
	//forks_data = forks;
	//forks_data = (t_forks *)malloc(sizeof(t_forks));
	while (++i < time_set.num_of_philo)
	    pthread_mutex_init(&forks->forks[i], NULL);
}