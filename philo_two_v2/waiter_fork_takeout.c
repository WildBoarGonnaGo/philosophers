#include "philo_two.h"

void					waiter_fork_takeout(t_philo_hands *data)
{
	sem_post(data->c_nerve->forks);
	sem_post(data->c_nerve->forks);
	data->left_hand = DROPFORK;
	data->right_hand = DROPFORK;
}