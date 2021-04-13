#include "philo_three.h"

void			philo_preparing_to_eat(t_fork_philo *philo)
{
	if (philo->left_hand == PHILO_PUT_FORK)
	{
		sem_wait(philo->misc_data->waiter);
		sem_wait(philo->misc_data->chopstick);
		calculate_time(philo, philo_takes_fork, 0);
		philo->left_hand = PHILO_TAKE_FORK;
		sem_post(philo->misc_data->waiter);
	}
	if (philo->right_hand == PHILO_PUT_FORK)
	{
		sem_wait(philo->misc_data->chopstick);
		calculate_time(philo, philo_takes_fork, 0);
		philo->right_hand = PHILO_TAKE_FORK;	
	}	
}