#include "philo_two.h"

void					philo_is_sleeping(t_philo_data *philo_data, long delta)
{
	printf("%ld %d is sleeping\n", philo_data->philo->time_travel,
	philo_data->philo->num + 1);
	philo_data->philo->philo_hp -= delta;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num + 1);
		philo_data->misc->error = PHDEATH;
	}
	else
	{
		printf("%ld %d is thinking\n", philo_data->philo->time_travel,
		philo_data->philo->num + 1);
	}
}