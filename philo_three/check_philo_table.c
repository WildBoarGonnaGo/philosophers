#include "philo_three.h"

void			*check_philo_table(void *data)
{
	t_fork_philo	*checker;

	checker = (t_fork_philo *)data;
	while (1)
	{
		if (checker->philo_hp <= 0 || checker->swallow ==
		checker->misc_data->num_of_time_philo_must_eat)
		{	
			if (checker->philo_hp <= 0)
			{
				sem_wait(checker->misc_data->dead_philo);
				sem_wait(checker->misc_data->msg);
				printf("%ld %d died\n", checker->dead_old_time, 
				checker->num + 1);
				sem_post(checker->misc_data->msg);
			}	
			return (NULL);
		}
	}
	return (NULL);
}