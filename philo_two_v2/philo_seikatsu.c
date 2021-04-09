#include "philo_two.h"

void					*philo_seikatsu(void *args)
{
	t_philo_hands	*sinner;

	sinner = (t_philo_hands *)args;
	while (1)
	{
		if (!waiter_give_fork(sinner))
			return (NULL);
		calculate_time(sinner, sinner->c_nerve->time_to_eat,
		philo_is_eating);
		if (sinner->c_nerve->error)
			return (NULL);
		waiter_fork_takeout(sinner);
		calculate_time(sinner, sinner->c_nerve->time_to_sleep,
		philo_is_sleeping);
		if (sinner->c_nerve->error)
			return (NULL);
		calculate_time(sinner, 0, philo_is_thinking);
		if (sinner->c_nerve->error)
			return (NULL);
	}
	return (NULL);
}