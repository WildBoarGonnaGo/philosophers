#include "philo_one.h"

void					philo_is_sleeping(t_philo_data *philo_data)
{
	printf("[%ld ms] philosopher %d is sleeping\n", philo_data->philo->time_travel,
	philo_data->philo->num);
	philo_data->philo->philo_hp -= philo_data->philo->input_time_data->time_to_sleep;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("[%ld ms] philosopher %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num);
		philo_data->philo->input_time_data->error = PHDEATH;
	}
	printf("[%ld ms] philosopher %d is thinking\n", philo_data->philo->time_travel,
	philo_data->philo->num);
}