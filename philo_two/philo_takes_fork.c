#include "philo_two.h"

void					philo_takes_fork(t_philo_data *philo_data, long delta)
{
	printf("%ld %d has taken a fork\n",
    philo_data->philo->time_travel,
	philo_data->philo->num + 1);
	philo_data->philo->philo_hp -= delta;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("[%ld ms] philosopher %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num + 1);
		philo_data->misc->error = PHDEATH;
	}
}