#include "philo_two.h"

void					philo_is_sleeping(t_philo_hands *philo_data, long delta)
{
	printf("%ld %d is sleeping\n",
    philo_data->dead_old_time, philo_data->num + 1);
	philo_data->philo_hp -= delta;
	if (philo_data->philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->dead_old_time,
		philo_data->num + 1);
		philo_data->c_nerve->error = PHDEATH;
	}
}