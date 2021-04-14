#include "philo_one.h"

void                    *philo_seikatsu(void *data)
{
	t_philo_data    *philo_manager;

	philo_manager = (t_philo_data *)data;
	while (1)
	{
		pthread_mutex_lock(&philo_manager->misc->take_forks);
		pthread_mutex_lock(philo_manager->philo.left_fork);
		calculate_time(philo_manager, 0, philo_takes_fork);
		if (philo_manager->misc->error)
			break ;
		pthread_mutex_unlock(&philo_manager->misc->take_forks);
		pthread_mutex_lock(philo_manager->philo.right_fork);
		calculate_time(philo_manager, 0, philo_takes_fork);
		if (philo_manager->misc->error)
			break ;
		calculate_time(philo_manager, philo_manager->misc->time_to_eat,
		philo_is_eating);
		if (philo_manager->misc->error)
			break ;
		pthread_mutex_unlock(philo_manager->philo.right_fork);
		pthread_mutex_unlock(philo_manager->philo.left_fork);
		calculate_time(philo_manager, philo_manager->misc->time_to_sleep,
		philo_is_sleeping);
		if (philo_manager->misc->error)
			break ;
	}
	return (NULL);
}