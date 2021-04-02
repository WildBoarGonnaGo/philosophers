#include "philo_one.h"

void					philo_takes_fork(t_philo_data *philo_data)
{
	printf("[%ld ms] philosopher %d has taken a fork\n",
    philo_data->philo->time_travel,
	philo_data->philo->num);
}