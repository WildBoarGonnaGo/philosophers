#include "philo_three.h"

int 			philo_is_eating(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	sem_wait(crnl->misc_data->msg);
	if (loop_condition(crnl))
		printf("%ld %d is eating\n", old_time, crnl->num + 1);
	sem_post(crnl->misc_data->msg);
	crnl->philo_hp = crnl->misc_data->time_to_die
	- diff_time * 1000;
	old_time *= 1;
	return (EXIT_SUCCESS);
}