#include "philo_one.h"

void					philo_is_eating(t_philo_data *philo_data, long delta)
{
	printf("%ld %d is eating\n", philo_data->philo.dead_old_time,
	philo_data->philo.num + 1);
	philo_data->philo.philo_hp = philo_data->misc->time_to_die - delta;
	if (philo_data->philo.philo_hp <= 0)
	{
		printf("%ld %d died\n", philo_data->philo.dead_old_time,
		philo_data->philo.num + 1);
		philo_data->misc->error = PHDEATH;
	}
	/*philo_data->philo->old_time = philo_data->philo->cur_time.tv_sec * 1000 +
    return_usec_round(philo_data->philo->cur_time.tv_usec);*/
}