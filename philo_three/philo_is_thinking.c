#include "philo_three.h"

int				philo_is_thinking(t_fork_philo *crnl, long diff_time,
				long old_time)
{
	sem_wait(crnl->misc_data->msg);
	if (loop_condition(crnl))
		printf("%ld %d is thinking\n", old_time, crnl->num + 1);
	sem_post(crnl->misc_data->msg);
	crnl->philo_hp -= diff_time * 1000;
	return (EXIT_SUCCESS);
}