#include "philo_three.h"

int				philo_lifetime(void *proc)
{
	pthread_t		watcher;
	t_fork_philo	*data;
	int				if_err;

	if_err = pthread_create(&watcher, NULL, check_philo_table, proc);
	if (if_err)
	{
		printf("philo_three: error: can't create a new thread\n");
		return (EXIT_FAILURE);
	}
	pthread_detach(watcher);
	data = (t_fork_philo *)proc;
	while (loop_condition(data))
	{
		if (loop_condition(data))
			philo_preparing_to_eat(data);
		if (loop_condition(data))
		calculate_time(data, philo_is_eating,
		data->misc_data->time_to_eat);
		if (loop_condition(data))
			philo_put_forks(data);
		data->swallow += 
		(data->misc_data->num_of_time_philo_must_eat != -1);
	}
	if (data->swallow == 
	data->misc_data->num_of_time_philo_must_eat)
		sem_wait(data->misc_data->swallow);
	return (EXIT_SUCCESS);
}