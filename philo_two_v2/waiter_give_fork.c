#include "philo_two.h"

int						waiter_give_fork(t_philo_hands *data)
{
	if (data->left_hand != TAKEFORK)
	{
		sem_wait(data->c_nerve->waiter);
		sem_wait(data->c_nerve->forks);
		data->left_hand = TAKEFORK;
		calculate_time(data, 0, philo_takes_fork);
		if (data->c_nerve->error)
			return (0);
		sem_post(data->c_nerve->waiter);
	}
	if (data->right_hand != TAKEFORK)
	{
		sem_wait(data->c_nerve->forks);
		data->right_hand = TAKEFORK;
		calculate_time(data, 0, philo_takes_fork);
		if (data->c_nerve->error)
			return (0);
	}
	return (1);
}