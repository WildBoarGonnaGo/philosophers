#include "philo_one.h"

void					philo_is_eating(t_philo_data *philo_data)
{
	printf("[%ld ms] philosopher %d is eating\n", philo_data->philo->time_travel,
	philo_data->philo->num);
	philo_data->philo->philo_hp = philo_data->philo->input_time_data->time_to_die -
	philo_data->philo->input_time_data->time_to_eat;
	if (philo_data->philo->philo_hp <= 0)
	{
		printf("[%ld ms] philosopher %d died\n", philo_data->philo->time_travel,
		philo_data->philo->num);
		philo_data->philo->input_time_data->error = PHDEATH;
	}
}