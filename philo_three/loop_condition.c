#include "philo_three.h"

int				loop_condition(t_fork_philo *obj)
{
	return (obj->misc_data->dead_philo->__size[0] &&
	(obj->swallow != obj->misc_data->num_of_time_philo_must_eat));
}