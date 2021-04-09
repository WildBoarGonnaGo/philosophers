#include "philo_two.h"

void					philo_is_eating(t_philo_hands *philo_data, long delta)
{
	printf("%ld %d is eating\n", philo_data->timeflow,
	philo_data->num + 1);
	philo_data->philo_hp = philo_data->c_nerve->time_to_die - delta;
	if (philo_data->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->timeflow,
		philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
}