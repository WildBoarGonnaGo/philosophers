#include "philo_one.h"

void					philo_is_eating(t_philo_data *philo_data, long delta)
{
	printf("%ld %d is eating\n", philo_data->philo->time_travel,
	philo_data->philo->num + 1);
	philo_data->philo->philo_hp = philo_data->misc->time_to_die - delta;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num + 1);
		philo_data->misc->error = PHDEATH;
	}
}