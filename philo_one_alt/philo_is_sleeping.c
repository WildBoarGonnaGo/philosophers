#include "philo_one.h"

void					philo_is_sleeping(t_philo_data *philo_data, long delta)
{
	printf("[%ld ms] philosopher %d is sleeping\n", philo_data->philo->time_travel,
	philo_data->philo->num + 1);
	//printf("philosoper %d philo_hp = %ld\n", philo_data->philo->num,
	//philo_data->philo->philo_hp);
	philo_data->philo->philo_hp -= delta;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("[%ld ms] philosopher %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num + 1);
		philo_data->misc->error = PHDEATH;
	}
	else
	{
		printf("[%ld ms] philosopher %d is thinking\n", philo_data->philo->time_travel,
		philo_data->philo->num + 1);
	}
}