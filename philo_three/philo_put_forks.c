#include "philo_three.h"

void			philo_put_forks(t_fork_philo *philo)
{
	sem_post(philo->misc_data->chopstick);
	philo->right_hand = PHILO_PUT_FORK;
	sem_post(philo->misc_data->chopstick);
	philo->left_hand = PHILO_PUT_FORK;
	calculate_time(philo, philo_is_sleeping, philo->
	misc_data->time_to_sleep);
	calculate_time(philo, philo_is_thinking, 0);
}